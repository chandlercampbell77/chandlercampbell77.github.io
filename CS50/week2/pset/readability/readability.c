#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    // ask user for text to analyze
    string text = get_string("Text: ");

    // letters per 100 words
    float L = count_letters(text) / count_words(text) * 100;

    // sentences per 100 words
    float S = count_sentences(text) / count_words(text) * 100;

    // formula to calculate reading level
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int readability = index;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", readability);
    }
}

// function to determine number of letters in text
float count_letters(string text)
{
    float letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // detects characters to determine letters
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// function to determine number of words in text
float count_words(string text)
{
    float words = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // detects spaces to determine words
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

// function to determine number of sentences in text
float count_sentences(string text)
{
    float sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // detects symbols that end sentences to determine sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}