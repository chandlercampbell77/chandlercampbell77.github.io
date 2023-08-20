import requests
import random
import sys


def main():
    # Manually create list of countries
    countries = [
        "China",
        "India",
        "United States",
        "Indonesia",
        "Pakistan",
        "Brazil",
        "Nigeria",
        "Bangladesh",
        "Russia",
        "Mexico",
        "Japan",
        "Ethiopia",
        "Philippines",
        "Egypt",
        "Vietnam",
        "DR Congo",
        "Turkey",
        "Iran",
        "Germany",
        "Thailand",
        "United Kingdom",
        "France",
        "Italy",
        "South Africa",
        "Myanmar",
        "South Korea",
        "Colombia",
        "Spain",
        "Ukraine",
        "Tanzania",
        "Argentina",
        "Uganda",
        "Kenya",
        "Poland",
        "Algeria",
        "Sudan",
        "Canada",
        "Morocco",
        "Iraq",
        "Afghanistan",
        "Uzbekistan",
        "Malaysia",
        "Peru",
        "Nepal",
        "Venezuela",
        "Saudi Arabia",
        "Ghana",
        "Yemen",
        "Mozambique",
        "Cameroon",
        "Madagascar",
        "Australia",
        "North Korea",
        "Niger",
        "Sri Lanka",
        "Romania",
        "Syria",
        "Mali",
        "Malawi",
        "Chile",
        "Kazakhstan",
        "Zambia",
        "Guatemala",
        "Ecuador",
        "Netherlands",
        "Senegal",
        "Cambodia",
        "Chad",
        "Zimbabwe",
        "Jordan",
        "Rwanda",
        "Guinea",
        "Somalia",
        "Haiti",
        "Tunisia",
        "Bolivia",
        "Belgium",
        "Cuba",
        "Greece",
        "Dominican Republic",
        "Czech Republic",
        "Sweden",
        "Portugal",
        "Azerbaijan",
        "Hungary",
        "Belarus",
        "United Arab Emirates",
        "Honduras",
        "Israel",
        "Tajikistan",
        "Switzerland",
        "Sierra Leone",
        "Hong Kong",
        "Laos",
        "Paraguay",
        "Libya",
        "Nicaragua",
        "El Salvador",
        "Kyrgyzstan",
        "Lebanon",
        "Singapore",
        "Denmark",
        "Finland",
        "Central African Republic",
        "Slovakia",
        "Norway",
        "Oman",
        "Costa Rica",
        "Liberia",
        "Ireland",
        "New Zealand",
        "Central African Republic",
        "Croatia",
        "Kuwait",
        "Panama",
        "Moldova",
        "Eritrea",
        "Georgia",
        "Bosnia and Herzegovina",
        "Uruguay",
        "Mongolia",
        "Armenia",
        "Jamaica",
        "Qatar",
        "Albania",
    ]

    # Getting the number of countries the user wants to guess
    n = get_number()

    # Generate n countries for user to guess, keeping track of which they guessed successfully
    score = 0
    for i in range(n):
        country_json = get_country_json(countries)
        facts = get_facts(country_json)
        country_name = facts[0]
        country_language = facts[1]
        print(f"{i + 1}. Can you guess what country I'm thinking of?\n")
        generate_question(*facts[2:])
        if check_guess(country_name, country_language):
            score += 1
        print(f"Score: {score}\n")

    # End program
    grade = calculate_percent(score, n)
    print(f"Grade: {grade}%\n")
    print(f"Thanks for playing! You correctly guessed {score} out of {n} countries!\n")
    sys.exit()

def get_number():
    # Welcome user and prompt them for how many countries they want to guess
    print("\nWelcome to CS50 Countries by Chandler Campbell!\n")
    n = int(input("How many countries do you want to guess? "))
    print()
    return n

def get_country_json(countries):
    # Communicating with the REST Countries API
    i = 0
    while True:
        response = requests.get(
            "https://restcountries.com/v3.1/name/"
            + random.choice(countries)
            + "?fullText=true"
        )
        if response.status_code == 200:
            break
        elif i == 2:
            print("There is an issue with the API. Please try again later.")
            raise Exception
        else:
            i += 1
    data = response.json()

    # Because we are only dealing with 1 country at a time, index into first element
    country = data[0]
    return country


def get_facts(country):
    # Access the values used for this program using keys
    name = country["name"]["common"]
    population = country["population"]
    languages = country["languages"]
    capital = country["capital"][0]
    continent = country["continents"][0]
    currencies = country["currencies"]

    # Necessary because unsure of key name and values in advance
    values = languages.values()
    for value in values:
        language = value
        break
    keys = currencies.keys()
    for key in keys:
        currency = key
        break

    # Returning the facts in a list for easy access later
    facts = [name, language, continent, population, currency, capital]
    return facts


def generate_question(continent, population, currency, capital):
    # Printing the clues for the user
    print(f"The country is located in the continent of {continent}")
    print(f"The country has a population of {format(population, ',')} people")
    print(f"They use {currency} for their currency")
    print(f"The capital is {capital}\n")
    print(f"Type skip and hit enter if you give up, otherwise you get 3 tries!\n")


def check_guess(country, language):
    # Using an infinite loop to check if user input matches the random country
    correct = False
    incorrect = 0
    while True:
        if incorrect == 3:
            print(f"\nThe name of the country was {country}. Better luck next time!\n")
            break
        guess = input("Guess: ")
        guess = guess.strip()
        if guess.lower() == "skip":
            print(f"\nThe name of the country was {country}. Better luck next time!\n")
            break
        elif guess.lower() == country.lower():
            print("\nYou are correct!\n")
            correct = True
            break
        else:
            incorrect += 1
            print("\nIncorrect\n")
            if incorrect == 1:
                print(f"Hint 1: The name of the country starts with '{country[0:2]}'\n")
            elif incorrect == 2:
                print(f"Hint 2: The people there speak {language}\n")
    return correct


def calculate_percent(correct, n):
    return float(correct / n) * 100


if __name__ == "__main__":
    main()
