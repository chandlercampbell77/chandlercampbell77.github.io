def main():
    foods = {}

    while True:
        try:
            food = input()
            food = food.strip().upper()
            if food not in foods:
                foods[food] = 1
            else:
                foods[food] += 1
        except EOFError:
            print()
            break

    foods = dict(sorted(foods.items(), key=lambda item: item[0]))
    for food in foods:
        print(foods[food], food)


main()