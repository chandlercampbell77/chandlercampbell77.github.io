def main():
    while True:
        fraction = input("Fraction: ")
        if "/" in fraction:
            numerator, denominator = fraction.split("/")
            try:
                numerator = int(numerator)
                denominator = int(denominator)
                fuel = float(numerator/denominator)
            except (ValueError, ZeroDivisionError):
                pass
            else:
                if numerator <= denominator:
                    fuel = int(round(fuel * 100))
                    if fuel <= 1:
                        print("E")
                    elif fuel >= 99:
                        print ("F")
                    else:
                        print(f"{fuel}%")
                    break


main()