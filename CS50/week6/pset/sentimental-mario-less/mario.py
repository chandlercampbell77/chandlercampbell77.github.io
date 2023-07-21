# import get_int function
from cs50 import get_int

# do while loop
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

# print pyramid using loop
for row in range(height):
    for space in range(height - 1, row, -1):
        print(" ", end="")
    for brick in range(0, row + 1, 1):
        print("#", end="")
    print()