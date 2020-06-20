//Standard Libraries
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//Function Declaration
void onlineInsertionSort (char inputFile[], char outputFile[]);
void swap(double *swap1, double *swap2);

//Main Function
int main(void) 
{
  //Strings for File Names
  char inputFile[30] = "";
  char outputFile[30] = "";

  //User Input File Names
  printf("Enter the name of the input file: ");
  scanf("%s", inputFile);
  printf("Enter the name of the output file (without file extenstion): ");
  scanf("%s", outputFile);

  //Calling Insertion Sort Function
  onlineInsertionSort(inputFile, outputFile);

  return 0;
}
//Insertion Sort
void onlineInsertionSort (char inputFile[], char outputFile[])
{
  //Initialization
  double number = 0;
  int length = 0;
  int current = 1;
  double* fileNumbers;

  //Input File
  FILE* spFileIn; 
  spFileIn = fopen(inputFile, "r");
  
  //Length Of File 
  while (fscanf(spFileIn, "%lf", &number) != EOF){
  	length++;
  }
 
  //Close Input File
  fclose(spFileIn);

  //Array
  fileNumbers = calloc(length, sizeof(double));
  
  //Open Input File
  spFileIn = fopen(inputFile, "r");

  //Put File Numbers into Array
  for (int i = 0; i < length; i++)
  {
    fscanf(spFileIn, "%lf", &fileNumbers[i]);
  }

  //Insertion Sort Loop
    //Outer Loop
    while (current < length)
    {
      //Inner Loop
      for(int i = current; i > 0; i--)
      {
        //If the previous number is larger than the current number
        if ((fileNumbers[i - 1] > fileNumbers[i]))
        {
          //Swap Numbers
          swap(&fileNumbers[i - 1], &fileNumbers[i]);
        }
      }
    current++;
    }

    fclose(spFileIn);

    //Output File
    FILE* spFileOut;
    spFileOut = fopen(outputFile, "a");

    //Sending Sorted Array to Output File
    for(int i = 0; i < length; i++)
    {
    fprintf(spFileOut, "%.6lf \n", fileNumbers[i]);
    }
  
    fclose(spFileOut);
 
  return;
}

//Swap Function
void swap(double *swap1, double *swap2)
{
  double temp = 0;
  temp = *swap1;
  *swap1 = *swap2; 
  *swap2 = temp;
  return;
}