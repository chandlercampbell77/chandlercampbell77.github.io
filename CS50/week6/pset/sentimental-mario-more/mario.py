# import get_int function
from cs50 import get_int

# do while loop
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

# print pyramid using loop
for row in range(height):
    print(" " * ((height - 1) - row), end="")
    print("#" * (row + 1), end="")
    print("  ", end="")
    print("#" * (row + 1), end="")
    print()