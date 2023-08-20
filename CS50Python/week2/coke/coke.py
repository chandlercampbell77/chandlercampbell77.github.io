def main():
    due = 50
    while True:
        print(f"Amount Due: {due}")
        coin = int(input("Insert Coin: "))
        if coin == 5 or coin == 10 or coin == 25:
            due = due - coin
        if due <= 0:
            print(f"Change Owed: {abs(due)}")
            break


main()