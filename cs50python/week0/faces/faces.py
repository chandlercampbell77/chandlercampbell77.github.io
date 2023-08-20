def main():
    userInput = input("Type a string and press enter: ")
    userInput = convert(userInput)
    print(userInput)


def convert(userInput):
    userInput = userInput.replace(":)", "🙂")
    userInput = userInput.replace(":(", "🙁")
    return userInput

main()