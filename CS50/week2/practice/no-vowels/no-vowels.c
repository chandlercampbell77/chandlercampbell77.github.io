// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// function declaration
string replace(string argv[1]);

// main function
int main(int argc, string argv[])
{
    // makes sure user only types in 1 word after the command to run the program
    if (argc < 2 || argc > 2)
    {
        printf("Error Code 1\n");
        return 1.0;
    }
    // prints new word
    else
    {
        printf("%s\n", replace(argv));
    }
}

string replace(string argv[])
{
    // figures out how many characters in word
    int wordlength = strlen(argv[1]);

    // checks for character replacement
    int i;

    for (i = 0; i < wordlength; i++)
    {
        if (argv[1][i] == 'a')
        {
            argv[1][i] = '6';
        }
        if (argv[1][i] == 'e')
        {
            argv[1][i] = '3';
        }
        if (argv[1][i] == 'i')
        {
            argv[1][i] = '1';
        }
        if (argv[1][i] == 'o')
        {
            argv[1][i] = '0';
        }
    }
    // stores new word into output of function
    return argv[1];
}
