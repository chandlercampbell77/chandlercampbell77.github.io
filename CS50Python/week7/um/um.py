import re


def main():
    print(count(input("Text: ")))


def count(s):
    counter = 0
    s = s.strip().lower()
    matches = re.findall(r"(\bum\b)", s, re.IGNORECASE)
    for _ in matches:
        counter += 1
    return counter


if __name__ == "__main__":
    main()