#include<cs50.h>
#include<stdio.h>


int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        //print space on the left side
        for (int s = 0; s < n - i - 1; s++)
        {
            printf(" ");
        }
        //print left bricks
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }
        //print the gap (two spaces)
        printf("  ");
        //print right bricks
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }


        printf("\n");
    }

}
