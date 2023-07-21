#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check that there is one cla
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check that the key consists only of letters
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage ./substitution key\n");
            return 1;
        }
    }

    // check that key consists of 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check for unique characters
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must contain unique letters.\n");
                return 1;
            }
        }
    }

    // get plaintext
    string plaintext = get_string("Plaintext:  ");

    // print ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", toupper(key[letter]));
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", tolower(key[letter]));
        }
        else printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}