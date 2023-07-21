#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // checking to validate input
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // base case
    if (input[0] == 0)
    {
        return 0;
    }
    else
    {
        // recursive case
        int lastchar = strlen(input) - 1;
        int number[strlen(input)];
        number[lastchar] = input[lastchar] - 48;
        input[lastchar] = input[lastchar + 1];
        return number[lastchar] + (10 * convert(input));
    }
}