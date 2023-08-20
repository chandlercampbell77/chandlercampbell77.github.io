from pyfiglet import Figlet
import random
import sys

def main():
    figlet = Figlet()
    fonts = figlet.getFonts()

    # Checking for errors
    if len(sys.argv) != 1 and len(sys.argv) != 3:
        sys.exit("Please provide zero or two command-line arguments")
    if len(sys.argv) == 3:
        if sys.argv[1] != "-f" and sys.argv[1] != "--font":
            sys.exit("First command should be '-f' or '--font'")
        elif sys.argv[2] not in fonts:
            sys.exit("That font doesn't exist")

    # Converting input
    txt = input("Input: ")
    if len(sys.argv) == 1:
        choice = random.choice(fonts)
        figlet.setFont(font=choice)
        print(figlet.renderText(txt))
    else:
        choice = sys.argv[2]
        figlet.setFont(font=choice)
        print(figlet.renderText(txt))


main()