#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    // check argument count
    if(argc != 2)
    {
        printf ("./caesar key\n");
        return 1;
    }
    //check if argv has only digits
    int n = strlen(argv[1]);
    for ( int i = 0; i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("./caesar key\n");
            return 1;
        }
    }
     //convert string to integers, atoi
     int k = atoi(argv[1])%26;

     //get plaintext from user
     string plaintext = get_string("plaintext:  ");
     //output
     printf("ciphertext: ");

     //shift letters
      for (int i = 0; i < strlen(plaintext); i++ )
      {
        //work with uppercase letters
        if(isupper(plaintext[i]))
        {
          int position = ((plaintext[i] - 'A') + k)%26 ;// convert letters number to 0-25 and calculate
          char encrypted = position + 'A'; //convert back to ASCII format
          printf("%c", encrypted);
        }
        else if (islower(plaintext[i]))
        {  //work with lowercase letters
            int position = ((plaintext[i] - 'a')+ k)%26;
            char encrypted = position + 'a';
            printf("%c", encrypted);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
      }

         printf("\n");
         return 0;

}

