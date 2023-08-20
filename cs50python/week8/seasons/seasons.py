import datetime
from datetime import date
from datetime import timedelta
import time
import inflect
import re
import sys


def main():
    birth = input("Date of Birth: ").strip()
    if re.search(r"^([0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9])$", birth, re.IGNORECASE):
       minutes = convert_date(birth)
       words = convert_minutes(minutes)
       print(words, "minutes")
    else:
        sys.exit("Not a valid date format. Please use YYYY-MM-DD format")


def convert_date(birth):
    year, month, day = birth.split("-")
    year = int(year)
    month = int(month)
    day = int(day)
    birth = datetime.date(year, month, day)
    today = date.today()
    difference = today - birth
    return int(round(difference.total_seconds() / 60))


def convert_minutes(minutes):
    p = inflect.engine()
    minutes = p.number_to_words(minutes, andword="")
    first_letter = minutes[0][0]
    return minutes.replace(first_letter, first_letter.upper(), 1)

if __name__ == "__main__":
    main()