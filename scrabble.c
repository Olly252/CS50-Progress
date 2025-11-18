#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string(word));
int main(void)
{
    // prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // declare values for each letter

    // get score for word1, and word 2
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // compare the scores
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}
// count the score of each words
int compute_score(string(word))
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            char letter = toupper(word[i]);
            int index = letter - 'A';
            score += values[index];
        }
    }
    return score;
}
