#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // iterate over each candidate to see if vote matches a candidate's name
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcasecmp(candidates[k].name, name) == 0)
        {
            preferences[voter][rank] = k;
            return true;
        }
    }
    // no match so return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // look at each voter's top choice who hasn't been eliminated
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                // tally up new votes
                candidates[preferences[i][j]].votes++;
                break;
            }
            // else the candidate is eliminated so it will move the next one
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // iterate over the vote total of each candidate
    for (int k = 0; k < candidate_count; k++)
    {
        // if the candidate has the majority of the votes, she is the winner
        if (candidates[k].votes > voter_count / 2)
        {
            printf("%s\n", candidates[k].name);
            return true;
        }
    }
    // else no candidate has a majority, no winner
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = candidates[0].votes;
    // iterating over each candidate
    for (int k = 0; k < candidate_count; k++)
    {
        // if they've been eliminated, we don't care what their vote total is because they can't be eliminated again
        if (candidates[k].eliminated == true)
        {
            break;
        }
        // else they haven't been eliminated, so we should check if their vote total is the min
        else if (min > candidates[k].votes)
        {
            min = candidates[k].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // iterating over each candidate to seeing if one of them has more than the min
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes > min)
        {
            return false;
        }
    }
    // else all candidates have the same min so there isn't a winner and we can't eliminate anyone
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // iterating over each candidate
    for (int k = 0; k < candidate_count; k++)
    {
        // if the candidate has the smallest number of votes and there isn't a winner yet, they are eliminated
        if (candidates[k].votes == min)
        {
            candidates[k].eliminated = true;
        }
    }
    return;
}