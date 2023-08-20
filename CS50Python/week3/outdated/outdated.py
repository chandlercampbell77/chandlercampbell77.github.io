def main():
    months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
    ]

    while True:
        date = input("Date: ")
        date = date.strip().title()
        if "/" in date:
            if date[0].isdigit():
                month, day, year = date.split("/")
                month = int(month)
                day = int(day)
                year = int(year)
                if month >= 1 and month <= 12:
                    if day <= 31:
                        print(f"{year}-{month:02}-{day:02}")
                        break
        elif "," in date:
            if not date[0].isdigit():
                for item in months:
                    if item in date:
                        date = date.replace(",", "")
                        month, day, year = date.split(" ")
                        month = months.index(month) + 1
                        day = int(day)
                        year = int(year)
                        break
                if day <= 31:
                    print(f"{year}-{month:02}-{day:02}")
                    break


main()