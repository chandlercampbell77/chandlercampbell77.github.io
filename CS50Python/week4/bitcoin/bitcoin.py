import requests
import sys
import json

def main():
    if len(sys.argv) != 2:
        sys.exit("Missing command-line argument")

    try:
        n = float(sys.argv[1])
    except ValueError:
        sys.exit("Command-line argument is not a number")

    try:
        response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    except requests.RequestException:
        sys.exit("Could not connect to API")

    o = response.json()
    btc = o["bpi"]["USD"]["rate_float"]
    amount = btc * n
    print(f"${amount:,.4f}")


main()