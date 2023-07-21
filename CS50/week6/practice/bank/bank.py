from cs50 import get_string

greeting = get_string("Greeting: ")
greeting = greeting.lower()
greeting = greeting.strip()

if greeting[0:5] == "hello":
    print("$0")
elif greeting[0] == "h":
    print("$20")
else:
    print("$100")