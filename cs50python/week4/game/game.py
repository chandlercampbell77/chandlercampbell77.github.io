import random
import sys

def main():
    level = 0
    while level < 1:
        try:
            level = int(input("Level: "))
        except ValueError:
            pass

    number = random.randint(1, level)

    while True:
        try:
            guess = int(input("Guess: "))
            if guess < number:
                print("Too small!")
            elif guess > number:
                print("Too large!")
            else:
                print("Just right!")
                sys.exit()
        except ValueError:
            pass


main()