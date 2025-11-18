#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt the user for change owed, in cents.
    int change;
    do
    {
      change  = get_int("Change owed: ");

    }
    while(change < 0);
    //calculate quarters you should give customer. Substract the valur of those quarters from cents.
    int quarter = 25;
    int quarters_needed = change/quarter;
    change = change % quarter;

    int dime = 10;
    int dimes_needed = change/dime;
    change = change % dime;

    int nickel = 5;
    int nickels_needed = change/nickel;
    change = change % nickel;

    int penny = 1;
    int pennies_needed = change/penny;
    change = change % penny;
    int total_sum = quarters_needed + dimes_needed + nickels_needed + pennies_needed;
    printf("Total sum: %i\n", total_sum);
}
