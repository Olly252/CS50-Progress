#include<cs50.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
   // propmt the user for the text
   string text = get_string("Text: ");
   //count numbers of letters, words, sentences.
   int letters = count_letters(text);
   int words = count_words(text);
   int sentences = count_sentences(text);


   // temporary print the results
  //printf("Letters: %d\n", letters);
   //printf("Words: %d\n", words);
   //printf("Sentences: %d\n", sentences);

   // declare and compute average of letters and sentances
   double L = ((double) letters/words)*100;
   double S = ((double) sentences/words)*100;

   //calculate the Coleman-Liau index
   double index = 0.0588 * L - 0.296 * S- 15.8;
//get and round grades
   int grade = (int) round(index);
//print the grades
   if (grade < 1)
   {
       printf("Before Grade 1\n");
   }
  else if( grade >=16)
  {
   printf("Grade 16+\n");
  }
  else
  {
   printf("Grade %d\n", grade);
  }
return 0;

}

int count_letters(string text)
{
   int count = 0;
   int i = 0;
   for (i =0; i < strlen(text); i++)
   {
      if (isalpha (text[i]))
      {
         count++;
      }
   }
    return count;
}

int count_words(string text)
 {
   int count = 1;
   int i;
   for (i = 0; i < strlen(text); i++)
   {
      if(text[i] == ' ')
      {
         count++;
      }
   }
   return count;
 }

int count_sentences(string text)
{
   int count = 0;
   int i;
   for (i = 0; i < strlen(text); i++)
   {
      if( text[i] == '.'|| text[i] == '!'|| text[i] == '?')
      {
         count++;
      }
   }
   return count;
}
