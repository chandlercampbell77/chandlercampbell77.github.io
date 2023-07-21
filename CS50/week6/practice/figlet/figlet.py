from sys import argv
from sys import exit
from pyfiglet import Figlet
from cs50 import get_string
import random
figlet = Figlet()


def main():
    if len(argv) != 1 and len(argv) != 3:
        exit("Invalid counts")
    if len(argv) == 3:
        if argv[1] != "-f" and argv[1] != "--font":
            exit("Invalid argv1")
        fonts = figlet.getFonts()
        match = 0
        for font in fonts:
            if font == argv[2]:
                match = 1
        if match == 0:
            exit("Invalid font")

    input = get_string("Input: ")

    if len(argv) == 3:
        figlet.setFont(font=argv[2])
        print(figlet.renderText(input))
        return
    elif len(argv) == 1:
        fonts = figlet.getFonts()
        randomfont = random.choice(fonts)
        figlet.setFont(font=randomfont)
        print(figlet.renderText(input))
        return

main()