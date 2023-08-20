import sys


def main():
    if len(sys.argv) == 2:
        if sys.argv[1].endswith(".py"):
            try:
                with open(sys.argv[1]) as file:
                    lines = file.readlines()
            except FileNotFoundError:
                sys.exit("File does not exist")
        else:
            sys.exit("Not a Python file")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    else:
        sys.exit("Too few command-line arguments")

    counter = 0
    for line in lines:
        line = line.strip()
        if line.startswith("#"):
            continue
        elif line == "":
            continue
        else:
            counter += 1

    print(counter)




if __name__ == "__main__":
    main()