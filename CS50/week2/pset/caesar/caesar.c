#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string cla);

int main(int argc, string argv[])
{
    // make sure program was run with just one command-line argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // make sure every character in argv[1] is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert argv[1] from a 'string' to an 'int'
    int key = atoi(argv[1]);

    // make sure key is positive
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // for each character in the plaintext:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = plaintext[i] - 'A';
                plaintext[i] = (plaintext[i] + key) % 26;
                plaintext[i] = plaintext[i] + 'A';
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = plaintext[i] - 'a';
                plaintext[i] = (plaintext[i] + key) % 26;
                plaintext[i] = plaintext[i] + 'a';
            }
        }
    }
    // printing the ciphertext!
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

bool only_digits(string cla)
{
    // creating function to detect that only a number was entered
    int j = 0;
    for (int i = 0; i < strlen(cla); i++)
    {
        if (isdigit(cla[i]))
        {
            j++;
        }
    }
    // if each of the characters entered are digits, then true
    if (j == strlen(cla))
    {
        return true;
    }
    else
    {
        return false;
    }
}