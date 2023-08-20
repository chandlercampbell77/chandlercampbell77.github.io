import emoji

def main():
    txt = input("Input: ")
    txt = txt.strip().lower()
    print("Output:", emoji.emojize(txt, language="alias"))


main()