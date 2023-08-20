def main():
    text = input("Input: ")
    text = text.strip()
    text = shorten(text)


def shorten(text):
    text = text.replace("A", "")
    text = text.replace("E", "")
    text = text.replace("I", "")
    text = text.replace("O", "")
    text = text.replace("U", "")
    text = text.replace("a", "")
    text = text.replace("e", "")
    text = text.replace("i", "")
    text = text.replace("o", "")
    text = text.replace("u", "")
    return text


if __name__ == "__main__":
    main()