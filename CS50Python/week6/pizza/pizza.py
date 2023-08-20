import sys
import csv
from tabulate import tabulate

def main():

    # Checking for errors and if no errors, reading file
    if len(sys.argv) == 2:
        if sys.argv[1].endswith(".csv"):
            try:
                with open(sys.argv[1]) as file:
                    lines = []
                    reader = csv.reader(file)
                    for row in reader:
                        lines.append(row)
            except FileNotFoundError:
                sys.exit("File does not exist")
        else:
            sys.exit("Not a CSV file")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    else:
        sys.exit("Too few command-line arguments")

    # Printing csv file using tabulate function
    table = lines[1:]
    headers = lines[0]
    print(tabulate(table, headers, tablefmt="grid"))

if __name__ == "__main__":
    main()