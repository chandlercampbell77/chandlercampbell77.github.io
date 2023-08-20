def main():
    while True:
        fraction = input("Fraction: ")
        if "/" in fraction:
            percentage = convert(fraction)
            if percentage != -1:
                fuel = gauge(percentage)
                print(fuel)
                break


def convert(fraction):
        numerator, denominator = fraction.split("/")
        try:
            numerator = int(numerator)
            denominator = int(denominator)
        except ValueError:
            raise ValueError
        try:
            fuel = float(numerator/denominator)
        except ZeroDivisionError:
            raise ZeroDivisionError
        if numerator <= denominator:
            return int(round(fuel * 100))
        else:
            raise ValueError


def gauge(percentage):
    if percentage <= 1:
        return "E"
    elif percentage >= 99:
        return "F"
    else:
        return f"{percentage}%"


if __name__ == "__main__":
    main()