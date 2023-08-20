import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    print()
    s = s.strip()
    if matches := re.search(r".+iframe.+(https?://(?:www\.)?youtube\.com/embed/[a-z0-9_]+).+iframe.+", s, re.IGNORECASE):
        url = matches.group(1)
        domain, ext = url.split("embed/")
        return f"https://youtu.be/{ext}"
    else:
        return None


if __name__ == "__main__":
    main()