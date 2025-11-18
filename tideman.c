#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    if(strcmp(candidates[i], name) == 0)
    {
        ranks[rank] = i;
        return true;
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
          // up date global variables preferences
          preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count-1; i++)// outer loop
    {
        for (int j = i+1; j < candidate_count; j++)//inner loop
        {
          if(preferences[i][j] > preferences[j][i])
          {
            pairs[pair_count].winner =i;
          pairs[pair_count].loser = j;
          pair_count++;
          }

        else if(preferences[j][i] > preferences[i][j])
          {
          pairs[pair_count].winner = j;
          pairs[pair_count].loser  = i;
          pair_count++;
          }
        }

    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // check every pair
    for (int i = 0; i < pair_count; i++)
    {
        //check prefernces  pairs
        for (int j = i + 1; j < pair_count; j++)
        {
            //create strength i and j and compare
            int strength_i = preferences[pairs[i].winner][pairs[i].loser];
            int strength_j = preferences[pairs[j].winner][pairs[j].loser];
            if (strength_j > strength_i)
            {
                //swap the pairs
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
                //update strength
                strength_i = strength_j;
            }
        }

    }
    return;
}
//creat a helper function to creat a cycle
   bool creat_cycle(int winner, int current)
   {
    // do a basic case where cycle is found!
    if (winner == current)
    {
        return true;
    }
      // if cycle not found continue to chek candidates
      for (int i = 0; i < candidate_count; i++)
      {
        if(locked[current][i])// check if curren beats i (others candidates)
        {
            if(creat_cycle(winner, i))// call recursive function, to check if others candidates(i) cand reach the winner
            {
                return true;
            }
        }

      }
      return false;
    }


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    // Check pairs
    for (int i = 0; i < pair_count; i++)
    {
        if(! creat_cycle(pairs[i].winner, pairs[i].loser))// if addidng this pair will NOT create a cycle!
        {
            locked[pairs[i].winner][pairs[i].loser] = true;// lock this pair winner beats loser
        }
     }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
// check each candidate to find the one nobody beats
    for ( int i = 0; i < candidate_count; i++)
    {
        bool defeated = false; // assume that this candidate is undefeated
        for( int j = 0; j < candidate_count; j++)
        {
            if(locked[j][i] == true) // if anyone beats the candidate i
            {
                defeated = true;     // if true, mark is as defeated
                break;               // stop checking
            }
        }
         if(! defeated) // if nobody defeted the candidate i
         {
            printf("%s\n", candidates[i]); // they are the winner
            return;
         }
    }
    return;
}

