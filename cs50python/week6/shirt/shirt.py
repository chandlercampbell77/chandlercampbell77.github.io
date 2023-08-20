import sys
from PIL import Image, ImageOps
import os


def main():
    length = len(sys.argv)
    if length > 3:
        sys.exit("Too many command-line arguments")
    elif length < 3:
        sys.exit("Too few command-line arguments")
    input = sys.argv[1]
    output = sys.argv[2]
    shirt = "shirt.png"
    input_name, input_ext = os.path.splitext(input)
    input_ext = input_ext.lower()
    output_name, output_ext = os.path.splitext(output)
    output_ext = output_ext.lower()
    if input_ext != ".jpg" and input_ext != ".jpeg" and input_ext != ".png":
        sys.exit("Input is not a valid picture file")
    elif output_ext != ".jpg" and output_ext != ".jpeg" and output_ext != ".png":
        sys.exit("Output is not a valid picture file")
    elif input_ext != output_ext:
        sys.exit("Input must have same extension as output")
    else:
        try:
            input = Image.open(input)
            shirt = Image.open(shirt)
            size = shirt.size
            input = ImageOps.fit(input, size)
            input.paste(shirt, shirt)
            input.save(output)
        except FileNotFoundError:
            sys.exit("Input file not found")


if __name__ == "__main__":
    main()