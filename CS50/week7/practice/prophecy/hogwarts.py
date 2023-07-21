import csv
from cs50 import SQL


with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    # Open database
    db = SQL("sqlite:///roster.db")

    # Search for title
    for row in reader:
        student_id = row["id"]
        name = row["student_name"]
        house = row["house"]
        head = row["head"]
        if house == "Gryffindor":
            house_id = 1
        elif house == "Hufflepuff":
            house_id = 2
        elif house == "Ravenclaw":
            house_id = 3
        elif house == "Slytherin":
            house_id = 4


        student = db.execute("INSERT INTO students (id, student_name) VALUES (?, ?)", student_id, name)
        house = db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", house, head)
        assignment = db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, ?)", student_id, house_id)