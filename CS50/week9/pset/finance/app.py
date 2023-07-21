import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    users = db.execute("SELECT * FROM users;")
    if not users:
        return render_template("register.html")
    portfolios = db.execute("SELECT * FROM portfolios WHERE user_id = (?);", session["user_id"])
    for x in portfolios:
        stock = lookup(x["symbol"])
        value = stock["price"] * int(x["shares"])
        db.execute("UPDATE portfolios SET price = (?), value = (?) WHERE user_id = (?) AND name = (?);",
                   stock["price"], value, session["user_id"], x["name"])
    portfolios = db.execute("SELECT * FROM portfolios WHERE user_id = (?);", session["user_id"])
    row = db.execute("SELECT * FROM users WHERE id = ?;", session["user_id"])
    cash = row[0]["cash"]
    total = cash
    for x in portfolios:
        total += x["value"]
    return render_template("index.html", portfolios=portfolios, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        stock = lookup(request.form.get("symbol"))
        if not stock:
            return apology("lookup was unsuccessful. type in correct symbol.", 400)
        if not request.form.get("shares"):
            return apology("must provide number of shares", 400)
        try:
            if int(request.form.get("shares")) < 1:
                return apology("must buy at least 1 share", 400)
        except ValueError:
            return apology("please enter a positive integer", 400)
        row = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        if row[0]["cash"] - (int(request.form.get("shares")) * stock["price"]) < 0:
            return apology("not enough cash", 400)
        type = "buy"
        newcash = row[0]["cash"] - (int(request.form.get("shares")) * stock["price"])
        db.execute("INSERT INTO transactions (type, symbol, shares, price, user_id) VALUES (?, ?, ?, ?, ?);", type,
                   request.form.get("symbol"), request.form.get("shares"), stock["price"], session["user_id"])
        db.execute("UPDATE users SET cash = (?) WHERE id = (?);", newcash, session["user_id"])
        value = int(request.form.get("shares")) * stock["price"]
        portfolios = db.execute("SELECT * FROM portfolios;")
        match = False
        for x in portfolios:
            if x["name"] == stock["name"]:
                newshares = int(x["shares"]) + int(request.form.get("shares"))
                newvalue = x["value"] + value
                match = True
        if match == True:
            db.execute("UPDATE portfolios SET shares = (?), price = (?), value = (?) WHERE user_id = (?) AND name = (?);",
                       newshares, stock["price"], newvalue, session["user_id"], stock["name"])
            return redirect("/")
        else:
            db.execute("INSERT INTO portfolios (name, symbol, shares, price, value, user_id) VALUES (?, ?, ?, ?, ?, ?);",
                       stock["name"], request.form.get("symbol"), request.form.get("shares"), stock["price"], value, session["user_id"])
            return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ?;", session["user_id"])
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        stock = lookup(request.form.get("symbol"))
        if not stock:
            return apology("lookup was unsuccessful. type in correct symbol.", 400)
        return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists
        if len(rows) != 0:
            return apology("username already exists", 400)

        # Ensure password was submitted
        if not request.form.get("password") or not request.form.get("confirmation"):
            return apology("must provide password", 400)

        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        hash = generate_password_hash(request.form.get("password"))

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?);", request.form.get("username"), hash)

        user = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        session["user_id"] = user[0]["id"]

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        portfolios = db.execute("SELECT * FROM portfolios WHERE user_id = (?);", session["user_id"])
        return render_template("sell.html", portfolios=portfolios)
    else:
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)
        stock = lookup(request.form.get("symbol"))
        if not stock:
            return apology("lookup was unsuccessful. please try again.", 400)
        if not request.form.get("shares"):
            return apology("must provide number of shares", 400)
        try:
            if int(request.form.get("shares")) < 1:
                return apology("must sell at least 1 share", 400)
        except ValueError:
            return apology("please enter a positive integer", 400)
        portfolio = db.execute("SELECT * FROM portfolios WHERE user_id = (?) AND symbol = (?)",
                               session["user_id"], request.form.get("symbol"))
        if not portfolio:
            return apology("you do not own that stock", 400)
        if int(portfolio[0]["shares"]) < int(request.form.get("shares")):
            return apology("you cannot sell more shares than you own", 400)
        type = "sell"
        user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        newcash = user[0]["cash"] + (int(request.form.get("shares")) * stock["price"])
        db.execute("INSERT INTO transactions (type, symbol, shares, price, user_id) VALUES (?, ?, ?, ?, ?);", type,
                   request.form.get("symbol"), request.form.get("shares"), stock["price"], session["user_id"])
        db.execute("UPDATE users SET cash = (?) WHERE id = (?);", newcash, session["user_id"])
        value = int(request.form.get("shares")) * stock["price"]
        portfolios = db.execute("SELECT * FROM portfolios;")
        for x in portfolios:
            if x["name"] == stock["name"]:
                newshares = int(x["shares"]) - int(request.form.get("shares"))
                newvalue = x["value"] - value
        db.execute("UPDATE portfolios SET shares = (?), price = (?), value = (?) WHERE user_id = (?) AND name = (?);",
                   newshares, stock["price"], newvalue, session["user_id"], stock["name"])
        portfolios = db.execute("SELECT * FROM portfolios;")
        for x in portfolios:
            if int(x["shares"]) < 1:
                db.execute("DELETE FROM portfolios WHERE user_id = (?) AND name = (?);", session["user_id"], x["name"])
        return redirect("/")


@app.route("/deposit", methods=["GET", "POST"])
@login_required
def deposit():
    """Deposit cash."""
    if request.method == "GET":
        return render_template("deposit.html")
    else:
        deposit = int(request.form.get("amount"))
        user = db.execute("SELECT * FROM users WHERE id = ?;", session["user_id"])
        cash = user[0]["cash"]
        newcash = deposit + cash
        db.execute("UPDATE users SET cash = (?) WHERE id = (?);", newcash, session["user_id"])
        return redirect("/")


@app.route("/withdraw", methods=["GET", "POST"])
@login_required
def withdraw():
    """Withdraw cash."""
    if request.method == "GET":
        return render_template("withdraw.html")
    else:
        withdraw = int(request.form.get("amount"))
        user = db.execute("SELECT * FROM users WHERE id = ?;", session["user_id"])
        cash = user[0]["cash"]
        newcash = cash - withdraw
        db.execute("UPDATE users SET cash = (?) WHERE id = (?);", newcash, session["user_id"])
        return redirect("/")