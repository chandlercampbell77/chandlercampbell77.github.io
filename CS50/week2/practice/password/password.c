// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // create bools for each of the requirements
    bool checkUpper = false;
    bool checkLower = false;
    bool checkNumber = false;
    bool checkSymbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            checkUpper = true;
        }
        if (islower(password[i]))
        {
            checkLower = true;
        }
        if (isdigit(password[i]))
        {
            checkNumber = true;
        }
        if (!isalnum(password[i]))
        {
            checkSymbol = true;
        }
    }
    // check if each of the requirements were met
    if (checkUpper == true && checkLower == true && checkNumber == true && checkSymbol == true)
    {
        return true;
    }

    return false;
}
