import sys
import csv

def main():
    # Checking for errors and if no errors, reading from file and writing to a new file
    if len(sys.argv) == 3:
        if sys.argv[1].endswith(".csv") and sys.argv[2].endswith(".csv"):
            try:
                with open(sys.argv[1]) as file:
                    students = []
                    reader = csv.DictReader(file)
                    for row in reader:
                        name = row["name"]
                        last, first = name.split(",")
                        first = first.strip()
                        house = row["house"]
                        students.append({"first": first, "last": last, "house": house})
            except FileNotFoundError:
                sys.exit(f"Could not read {sys.argv[1]}")
            with open(sys.argv[2], "w") as file:
                writer = csv.DictWriter(file, fieldnames=["first", "last", "house"])
                writer.writeheader()
                for student in students:
                    writer.writerow({"first": student["first"], "last": student["last"], "house": student["house"]})
        else:
            sys.exit("One or more files are not csv files")
    elif len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    else:
        sys.exit("Too few command-line arguments")


if __name__ == "__main__":
    main()