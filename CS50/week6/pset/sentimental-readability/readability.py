from cs50 import get_string


def main():
    # ask user for text to analyze
    text = get_string("Text: ")

    # letters per 100 words
    L = count_letters(text) / count_words(text) * 100

    # sentences per 100 words
    S = count_sentences(text) / count_words(text) * 100

    # formula to calculate reading level
    index = 0.0588 * L - 0.296 * S - 15.8
    index = round(index)
    readability = index

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {readability}")


# function to determine number of letters in text
def count_letters(text):
    letters = 0
    for i in range(len(text)):
        # detects characters to determine letters
        if text[i].isupper() or text[i].islower():
            letters += 1
    return letters


# function to determine number of words in text
def count_words(text):
    words = 1
    for i in range(len(text)):
        # detects spaces to determine words
        if text[i].isspace():
            words += 1
    return words


# function to determine number of sentences in text
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        # detects symbols that end sentences to determine sentences
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1
    return sentences


main()