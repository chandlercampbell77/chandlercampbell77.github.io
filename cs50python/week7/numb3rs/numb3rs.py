import re

def main():
    ip = input("IPv4 Address: ").strip()
    if validate(ip):
        print("Valid")
    else:
        print("Invalid")


def validate(ip):
    if re.search(
        r"^([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$",
        ip,
    ):
        return True
    else:
        return False


if __name__ == "__main__":
    main()