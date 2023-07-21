// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 5000;

// Hash table
node *table[N];

// initialize word count variable
int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to obtain a hash value
    int index = hash(word);

    // access linked list at that index in the hash table
    node *cursor = table[index];

    // traverse linked list, looking for the word (strcasecmp)
    while (cursor != NULL)
    {
        // if the first word of the linked list is the word we are looking for
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // otherwise
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash function using ascii values

    int ascii = 0;
    // iterate over each character of the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // add character ascii value to ascii sum
        ascii += toupper(word[i]);
    }
    ascii = ascii * strlen(word);
    // return a value between 0 and N
    return ascii % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // create buffer to read into
    char buffer[LENGTH + 1];

    // read strings from file one at a time
    while (fscanf(dict, "%s", buffer) != EOF)
    {
        // create a new node for each word
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Couldn't allocate memory for new node.\n");
            return false;
        }
        // copy buffer into string location of node
        strcpy(new->word, buffer);
        // increment word counter by 1
        wordcount++;

        // hash word to obtain a hash value
        int index = hash(buffer);

        // insert node into hash table at that location
        new->next = table[index];
        table[index] = new;
    }

    // close dictionary
    fclose(dict);

    // creation of hash table successful
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // we kept track of the number of words in load function, so just return that
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // create node cursor to point to the next node
    node *cursor = table[0];

    // create temporary node pointer to keep track of current node
    node *tmp = table[0];

    // iterate over every hash value
    for (int i = 0; i < N; i++)
    {
        // set the cursor to the first node in a given linked list
        cursor = table[i];

        // free every node in a given linked list
        while (cursor != NULL)
        {
            // keep track of current node
            tmp = cursor;

            // navigate to the next node
            cursor = cursor->next;

            // free the current node
            free(tmp);
        }
    }

    // if the cursor does not equal NULL, then it never reached the end of a given linked list
    if (cursor != NULL)
    {
        return false;
    }

    // otherwise, freeing nodes was successful
    return true;
}