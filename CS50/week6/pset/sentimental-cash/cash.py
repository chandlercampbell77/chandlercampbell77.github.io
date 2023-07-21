from cs50 import get_float


def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = (100 * cents - quarters * 25) / 100

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = (100 * cents - dimes * 10) / 100

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = (100 * cents - nickels * 5) / 100

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = (100 * cents - pennies * 1) / 100

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(f"{coins}")


def get_cents():
    # Asks user for number of cents owed
    cents = -1.00
    while cents < 0.00:
        cents = get_float("Change owed: ")
    return cents


def calculate_quarters(cents):
    # Calculates the number of quarters owed
    quarters = cents / 0.25
    return int(quarters)


def calculate_dimes(cents):
    # Calculates the number of dimes owed
    dimes = cents / 0.10
    return int(dimes)


def calculate_nickels(cents):
    # Calculates the number of nickels owed
    nickels = cents / 0.05
    return int(nickels)


def calculate_pennies(cents):
    # Calculates the number of pennies owed
    pennies = cents / 0.01
    return int(pennies)


main()