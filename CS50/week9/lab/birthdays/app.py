import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        nameadd = request.form.get("nameadd")
        monthadd = request.form.get("monthadd")
        dayadd = request.form.get("dayadd")
        namedel = request.form.get("namedel")
        monthdel = request.form.get("monthdel")
        daydel = request.form.get("daydel")

        if not nameadd or not monthadd or not dayadd:
            if not namedel or not monthdel or not daydel:
                return redirect("/")
        if not namedel or not monthdel or not daydel:
            if not nameadd or not monthadd or not dayadd:
                return redirect("/")
        if nameadd and monthadd and dayadd:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);", nameadd, monthadd, dayadd)
            return redirect("/")
        if namedel and monthdel and daydel:
            db.execute("DELETE FROM birthdays WHERE name = (?) AND month = (?) AND day = (?);", namedel, monthdel, daydel)
            return redirect("/")

    else:

        # Display the entries in the database on index.html
        rows = db.execute("SELECT * FROM birthdays;")

        return render_template("index.html", birthdays=rows)


