def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(plate):
    if not plate[0:2].isalpha():
        return False
    if not len(plate) >= 2:
        return False
    if not len(plate) <= 6:
        return False
    numbers = 0
    for i in range(len(plate)):
        if plate[i].isdigit():
            numbers += 1
            if numbers == 1:
                if plate[i] == "0":
                    return False
            if i < len(plate) - 1:
                if plate[i+1].isalpha():
                    return False
        if not plate[i].isalnum():
            return False
    return True


if __name__ == "__main__":
    main()