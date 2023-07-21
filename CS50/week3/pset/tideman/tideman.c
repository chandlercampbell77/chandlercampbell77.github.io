#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

// number of pairs
int pair_count;
// number of candidates
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
// new function created
bool iscycle(int winner, int loser);

// command line argument gets number of candidates and their names
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates -- argc - 1 because we don't want to count the ./tideman argument
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs -- so far, no candidate wins
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // initializing pair count variable
    pair_count = 0;
    // prompting user for input
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference -- 0 is first preference, 1 is second preference etc.
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // prompting user for their ranks
            string name = get_string("Rank %i: ", j + 1);

            // update ranks as long as vote is valid, otherwise end program
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        // for each voter, record their preferences by updating preferences 2d array
        // for example, if voter prefers Alice over Charlie, preferences["Alice" 0]["Charlie" 2] == 1
        // if the next voter also prefers ALice over Charlie, preferences[0][2] == 2
        record_preferences(ranks);

        printf("\n");
    }
    // given a pair of candidates, is one prefered over the other? For example, if preferences[0][2] = 2, what does preferences[2][0] equal?
    // if [2][0] is different than 2, than that means a different number of people prefer Alice over Charlie than Charlie over Alice, so when of them is preferred by more voters
    // if one is preffered by more voters, then one has to be a winner and the other has to be the loser, so we should add them to the pairs struct array
    add_pairs();

    // we have our pairs of candidates where one if preferred over another, so now we need to sort them in order of decreaasing strength because we need to lock in the strongest pairs first
    // the strongest pairs means the strongest margin of victory. For example, say preferences[0][2] = 2 but preferencers[2][0] = 6. That means 2 voters prefer Alice over Charlie but 6 voters prefer Charlie over Alice.
    // To get margin of victory, take the winner's number of voters minus the loser's number of voters (6-2, so strength of victory is 4).
    // we can use bubble sort for this
    sort_pairs();

    // this is where we create the "graph."
    // if locked[2][0] == true, then we have drawn an arrow from Charlie to Alice
    lock_pairs();

    // determine the winner by picking the candidate who is the source of the graph, meaning that under the condition of no cycles, no candidate is preferred over the winner.
    print_winner();
    // end program because a winner was chosen
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Iterate over each candidate's name
    for (int i = 0; i < candidate_count; i++)
    {
        // if the name of the candidate and the vote entered match, then record their ranks
        if (strcasecmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    // no match, so invalid vote
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // iterate over each candidate who is preferred
    for (int i = 0; i < candidate_count; i++)
    {
        // iterate over each candidate who is not preferred
        for (int j = i + 1; j < candidate_count; j++)
        {
            // what this does is record their preferences
            // say that a voter's ballot looks like ranks[1, 0, 2]. This means that this voter preferes Bob over Alice, Bob over Charlie, Alice over Charlie
            // each of those preferences will be recorded. So preferences[1][0] = 1, preferences [1][2] = 1, preferences[0][2] = 1.
            // the function will repeat for each voter, because in main it is in a loop for each voter
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // iterate over each row of preferences array
    for (int row = 0; row < candidate_count; row++)
    {
        for (int col = row + 1; col < candidate_count; col++)
        {
            // iterate over each column of preferences array
            if (preferences[row][col] > preferences[col][row])
            {
                // the amount of people that prefer candidate in row to candidate in col is greater than col to row, so row is winner and col is loser
                // pair count starts at zero, so we can use this to start the array
                pairs[pair_count].winner = row;
                pairs[pair_count].loser = col;
                // we added a pair so we can need to increase the pair count
                pair_count++;
            }
            else if (preferences[col][row] > preferences[row][col])
            {
                // this is the same thing but opposite scenario
                pairs[pair_count].winner = col;
                pairs[pair_count].loser = row;
                pair_count++;
            }
            // hidden here is the scenario where preferences[row][col] == preferences[col][row]
            // in that scenario, we do nothing and move on to the next iteration because there is no winner and loser to declare
        }
    }
    // we have added all the winners and losers that exist into each pair so we can move on!
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // creating a variable (of type pair) to temporarily hold the value of one pair if we need to switch them
    pair sort;

    // iterating over each pair
    for (int i = 0; i < pair_count; i++)
    {
        // iterating over each pair still unsorted
        // minus by i because i is the value of pairs that have been sorted
        // minus by 1 because if we go to the last pair, there is nothing to the right of it to compare it to
        for (int j = 0; j < pair_count - i - 1; j++)
        {

            // for each pair unsorted, we need to determine the strength of a pair and the pair one spot to the right
            int strpair1 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            int strpair2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];

            // if in ascending order, swap them because we want descending order
            if (strpair1 < strpair2)
            {
                // assigning sort the value of the first pair because we need to swap the pairs but we can't do that simutaneously
                sort = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = sort;
            }
        }
    }
    // end function because we have sorted the pairs
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // iterate over each pair
    for (int i = 0; i < pair_count; i++)
    {
        // as long as doing so would not create a cycle, lock that pair in (draw an arrow from the winner to the loser)
        // notice that we call another function here to determine if locking the pair would create a cycle
        if (!iscycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    // done locking pairs so we can end the function
    return;
}

bool iscycle(int winner, int loser)
{
    // to determine if cycle, we need to look backwards to see if by recording this lock, the current winner would be pointing backwards to the source of the graph
    // for example, say that we had locked[2][0]? and our current graph looked like locked[0][1], locked[1][2]. We can see that 0 has nobody pointing towards it
    // so 0 is the source of the graph. If we did locked[2][0] this would be creating a cycle because we would no longer have a source
    while (winner != loser && winner != -1)
    {
        // we want to find who connects to the current winner, but right now we haven't found that out
        bool found = false;

        // iterate over each candidate to see who locked in over the current winner
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner] == true)
            {
                // we found who points towards the current winner
                found = true;
                // but now we want to figure out who pointed towards that candidate
                winner = i;
            }
        }
        if (!found)
        {
            // if we didn't find a candidate that locked in over the current winner, that means that the winner is the source of the graph!
            // if they are the source of the graph, we can record their arrow on the graph because it is impossible to create a cycle
            // by setting winner equal to -1, we are ending the while loop because we know we won't create a cycle
            winner = -1;
        }
    }
    // if after tracing our steps backwards we discover that our winner would be pointing towards the source of the graph, we would be creating a cycle
    // if creating a cycle, then iscycle should return true
    if (winner == loser)
    {
        return true;
    }
    // if the winner is the source of the graph or if the lock would not otherwise create a cycle, then iscycle should return false
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // instead of iterating over rows then columns, we need to start with columns because if an entire column is false, that means nobody
    // is pointing towards that candidate and they are the source of the graph, therefore the winner
    for (int col = 0; col < candidate_count; col++)
    {
        // we want to count each time a cell in a column is false, because if all cells in the column are false, that is our winner
        int counter = 0;

        // iterate over each cell in the column
        for (int row = 0; row < candidate_count; row++)
        {
            if (locked[row][col] == false)
            {
                // update counter
                counter++;
            }

            if (counter == candidate_count)
            {
                // we found our winner! if counter equals the number of candidates, that means that no candidates point towards this particular candidate in the column
                // and they are the source of the graph! Let's print their name
                printf("%s\n", candidates[col]);
            }

        }
    }
    // we found and printed our winner, so function is done
    return;
}