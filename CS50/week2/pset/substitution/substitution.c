#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // make sure program was run with just one command-line argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // make sure key is 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // make sure key is alphabetical
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must be alphabetical.\n");
            return 1;
        }
    }

    // make sure each letter is contained once
    int alphabet[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < strlen(argv[1]); i++)
    {

        if (argv[1][i] == 'A' || argv[1][i] == 'a')
        {
            alphabet[0]++;
        }
        if (argv[1][i] == 'B' || argv[1][i] == 'b')
        {
            alphabet[1]++;
        }
        if (argv[1][i] == 'C' || argv[1][i] == 'c')
        {
            alphabet[2]++;
        }
        if (argv[1][i] == 'D' || argv[1][i] == 'd')
        {
            alphabet[3]++;
        }
        if (argv[1][i] == 'E' || argv[1][i] == 'e')
        {
            alphabet[4]++;
        }
        if (argv[1][i] == 'F' || argv[1][i] == 'f')
        {
            alphabet[5]++;
        }
        if (argv[1][i] == 'G' || argv[1][i] == 'g')
        {
            alphabet[6]++;
        }
        if (argv[1][i] == 'H' || argv[1][i] == 'h')
        {
            alphabet[7]++;
        }
        if (argv[1][i] == 'I' || argv[1][i] == 'i')
        {
            alphabet[8]++;
        }
        if (argv[1][i] == 'J' || argv[1][i] == 'j')
        {
            alphabet[9]++;
        }
        if (argv[1][i] == 'K' || argv[1][i] == 'k')
        {
            alphabet[10]++;
        }
        if (argv[1][i] == 'L' || argv[1][i] == 'l')
        {
            alphabet[11]++;
        }
        if (argv[1][i] == 'M' || argv[1][i] == 'm')
        {
            alphabet[12]++;
        }
        if (argv[1][i] == 'N' || argv[1][i] == 'n')
        {
            alphabet[13]++;
        }
        if (argv[1][i] == 'O' || argv[1][i] == 'o')
        {
            alphabet[14]++;
        }
        if (argv[1][i] == 'P' || argv[1][i] == 'p')
        {
            alphabet[15]++;
        }
        if (argv[1][i] == 'Q' || argv[1][i] == 'q')
        {
            alphabet[16]++;
        }
        if (argv[1][i] == 'R' || argv[1][i] == 'r')
        {
            alphabet[17]++;
        }
        if (argv[1][i] == 'S' || argv[1][i] == 's')
        {
            alphabet[18]++;
        }
        if (argv[1][i] == 'T' || argv[1][i] == 't')
        {
            alphabet[19]++;
        }
        if (argv[1][i] == 'U' || argv[1][i] == 'u')
        {
            alphabet[20]++;
        }
        if (argv[1][i] == 'V' || argv[1][i] == 'v')
        {
            alphabet[21]++;
        }
        if (argv[1][i] == 'W' || argv[1][i] == 'w')
        {
            alphabet[22]++;
        }
        if (argv[1][i] == 'X' || argv[1][i] == 'x')
        {
            alphabet[23]++;
        }
        if (argv[1][i] == 'Y' || argv[1][i] == 'y')
        {
            alphabet[24]++;
        }
        if (argv[1][i] == 'Z' || argv[1][i] == 'z')
        {
            alphabet[25]++;
        }
    }

    for (int y = 0; y < 26; y++)
    {
        if (alphabet[y] > 1)
        {
            printf("Each letter of the alphabet must be in your key exactly once.\n");
            return 1;
        }
    }

    // asks user for plaintext to encrypt
    string plaintext = get_string("plaintext:  ");

    // setting the key equal to the command line argument
    string key = argv[1];

    // array for capital alphabet
    char upperalphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // array for lowercase alphabet
    char loweralphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // printing a string
    printf("ciphertext: ");
    // creating a loop that's going to run the length of the plaintext
    for (int j = 0; j < strlen(plaintext); j++)
    {
        // loop for the length of the alphabet and key
        for (int i = 0; i < 26; i++)
        {
            if (plaintext[j] == upperalphabet[i])
            {
                printf("%c", toupper(key[i]));
            }
            else if (plaintext[j] == loweralphabet[i])
            {
                printf("%c", tolower(key[i]));
            }
            else if (!isalpha(plaintext[j]))
            {
                printf("%c", plaintext[j]);
                j++;
                if (j == strlen(plaintext))
                {
                    i = 26;
                }
            }
        }
    }
    printf("\n");
    return 0;
}