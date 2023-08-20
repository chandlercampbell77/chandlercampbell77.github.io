import inflect

def main():
    p = inflect.engine()
    names = []
    phrase = "Adieu, adieu, to"
    while True:
        try:
            name = input("Name: ")
            names.append(name)
        except EOFError:
            print()
            break


    print(phrase, p.join(names))


if __name__ == "__main__":
    main()