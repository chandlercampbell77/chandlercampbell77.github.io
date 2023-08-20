# CS50 Countries
#### Video Demo:
https://youtu.be/lmMwZsmFgws?si=BdJkPgWYGgyx8E04
#### Description:
This project utilizes the REST Countries API to help users learn about the countries around the world and test their knowledge. Required libraries include requests, random, and sys (see requirements.txt). First, the project requires user input to determine how many countries the user wants to try to guess.

Next, the main function calls a loop of n times based on user input. This loop is designed to handle one country at a time. The program connects to the API and several functions are used to determine the name, language, continent, population, currency, and capital of the randomly selected country. The user is then presented with several clues about the country and given the opportunity to guess it 3 times. After each unsuccessful guess, an additional clue is given. The user may also skip the country. If the user gets the question correct, then their score is increased by 1. Finally, after this process is repeated n times, the program prints out the percent correct and total correct guesses.

In terms of design, I did debate whether to use command-line arguments. I decided that my program targets those seeking to learn and I did not want to increase the barriers to access. Additionally, one of the early issues I ran into was that the API only returned 3 countries max at a time. Therefore, I could not dynamically access the full list of the countries that could be used in the API. To remedy this, I manually created a list with over 100 of the most populated countries.