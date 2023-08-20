import random

def main():
    n = get_level()
    correct = 0
    for _ in range(10):
        x = generate_integer(n)
        y = generate_integer(n)
        answer = x + y
        incorrect = 0
        while True:
            try:
                guess = int(input(f"{x} + {y} = "))
            except ValueError:
                print("EEE")
                incorrect += 1
            if guess == answer:
                correct += 1
                break
            else:
                print("EEE")
                incorrect += 1
            if incorrect == 3:
                print(f"{x} + {y} = {answer}")
                break

    print(f"Score: {correct}")


def get_level():
    n = 0
    while n < 1 or n > 3:
        try:
            n = int(input("Level: "))
        except ValueError:
            pass
    return n


def generate_integer(level):
    if level == 1:
        return random.randint(0, 9)
    elif level == 2:
        return random.randint(10, 99)
    elif level == 3:
        return random.randint(100, 999)
    else:
        raise ValueError


if __name__ == "__main__":
    main()