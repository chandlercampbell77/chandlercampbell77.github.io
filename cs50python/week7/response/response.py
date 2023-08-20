import validators

def main():
    text = input("What's your email address? ").strip()
    if validators.email(text):
        print("Valid")
    else:
        print("Invalid")


if __name__ == "__main__":
    main()