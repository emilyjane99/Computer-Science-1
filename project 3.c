#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  char character  = ' ';
  int  characters = 0;
  int  ascii      = 0;
  int  integers   = 0;
  float integer   = 0;
  int  words      = 0;
  int  space      = 0;
  int result      = 0;
  int wordResult  = 0;

  FILE* spInput;

  spInput = fopen("input.txt", "r");

  while(fscanf(spInput, "%c", &character) != EOF)
  {
    ascii = character;

      if (ascii == 32)
      {
      characters++;
      space++;
      words++;
      }
        else if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122) || ascii == 39 || ascii == 45 || ascii == 58 || ascii == 59 || ascii == 63 || (ascii >= 48 && ascii <= 57) || character == '\n')
        {
        characters++;
        }
          else if (ascii == 46 || ascii == 33)
          {
            words++;
            characters++;
          }
  }

  fclose(spInput);
  spInput = fopen("input.txt", "r");

   do
   {
     result = fscanf(spInput, "%f", &integer);
      if (result == 1)
      {
        integers++;
      }
   }
   while(fscanf(spInput, "%c", &character) != EOF);

  words = words - integers;

  printf ("------------------------- \n");
  printf ("Word      Count: %d   \n", words);
  printf ("Character Count: %d   \n", characters);
  printf ("Integer   Count: %d   \n", integers);
  printf ("------------------------- \n");
  
  fclose(spInput);

return 0;

}
