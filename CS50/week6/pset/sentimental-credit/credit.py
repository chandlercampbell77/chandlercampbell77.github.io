from cs50 import get_int
import sys


def main():
    # ask user for card
    while True:
        card = get_int("Card number: ")
        if card > 0:
            break

    # luhn calculation
    digits = [int(d) for d in str(card)]
    odd = digits[-1::-2]
    even = digits[-2::-2]
    total = 0
    total += sum(odd)
    for d in even:
        total += sum([int(d) for d in str(d*2)])

    # luhn says should be 0 if valid
    if int(total % 10) != 0:
        print("INVALID")
        sys.exit(0)

    # get length of card
    length = len(str(card))

    visa = card
    amex = card
    master = card

    # is card VISA?
    while visa >= 10:
        visa = int(visa/10)
    if visa == 4 and (length == 13 or length == 16):
        print("VISA")
        sys.exit(0)

    # is card AMEX?
    while amex >= 100:
        amex = int(amex/10)
    if length == 15 and (amex == 34 or amex == 37):
        print("AMEX")
        sys.exit(0)

    # is card Mastercard?
    while master >= 100:
        master = int(master/10)
    if length == 16 and (master == 51 or master == 52 or master == 53 or master == 54 or master == 55):
        print("MASTERCARD")
        sys.exit(0)
    else:
        print("INVALID")
        sys.exit(0)


main()