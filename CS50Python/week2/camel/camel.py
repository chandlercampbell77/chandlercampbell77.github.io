def main():
    camel = input("camelCase: ")
    camel = camel.strip()
    snake = ""
    for letter in camel:
        if letter.isupper():
            snake += "_"
            letter = letter.lower()
        snake += letter
    print(f"snake_case: {snake}")


main()