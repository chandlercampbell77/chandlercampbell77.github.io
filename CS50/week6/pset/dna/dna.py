import csv
from sys import argv
from sys import exit


def main():

    # Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Read database file into a variable
    csvfile = argv[1]
    with open(csvfile, "r") as file:

        # buffer variable
        database = []
        # print from file
        reader = csv.reader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    text = argv[2]
    with open(text, "r") as file:

        # read from file
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    strcounts = []
    if argv[1] == "databases/large.csv":
        AGATC = longest_match(sequence, "AGATC")
        strcounts.append(AGATC)
        TTTTTTCT = longest_match(sequence, "TTTTTTCT")
        strcounts.append(TTTTTTCT)
        AATG = longest_match(sequence, "AATG")
        strcounts.append(AATG)
        TCTAG = longest_match(sequence, "TCTAG")
        strcounts.append(TCTAG)
        GATA = longest_match(sequence, "GATA")
        strcounts.append(GATA)
        TATC = longest_match(sequence, "TATC")
        strcounts.append(TATC)
        GAAA = longest_match(sequence, "GAAA")
        strcounts.append(GAAA)
        TCTG = longest_match(sequence, "TCTG")
        strcounts.append(TCTG)
    elif argv[1] == "databases/small.csv":
        AGATC = longest_match(sequence, "AGATC")
        strcounts.append(AGATC)
        AATG = longest_match(sequence, "AATG")
        strcounts.append(AATG)
        TATC = longest_match(sequence, "TATC")
        strcounts.append(TATC)

    # Check database for matching profiles
    for row in database:
        match = 0
        for i in range(len(strcounts)):
            if row[i + 1] == str(strcounts[i]):
                match += 1
                if match == len(strcounts):
                    print(f"{row[0]}")
                    return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()