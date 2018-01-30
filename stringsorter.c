#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char ** argv)
{

  //Checks to make sure the user only inputed 1 argument. != 2 because argc will always account for program name
  if(argc != 2)
  {
    printf("INPUT ERROR! Expected only 1 argument. Program will now exit. (Surround input in quotes to combine as one argument) \n");
    return 0;
  }

  char currChar;
  int i,j; //index for arrays
  int charIndex = 0;
  int bufferIndex = 0;
  int sepArrayIndex = 0;
  int wordCount =0;

  //Creates a character array allocated with the size of the input string.
  char* strBuffer = malloc(strlen(argv[1]));
  //Clears the memory allocated above so theres no  random memory
  memset(strBuffer, '\0', strlen(argv[1]));
  //Array of seperated strings from the input
  char** sepArray = malloc(strlen(argv[1])*sizeof(char*));
  //clearing all parts of the 2d array with memset
  for(i = 0; i< strlen(argv[1]); i++)
  {
    sepArray[i] = malloc(strlen(argv[1]));
    memset(sepArray[i], '\0', strlen(argv[1]));
  }

  //sets current char to be the first char in the input string
  currChar = argv[1][charIndex];
  //Runs to the end of the input string
  while(currChar!= '\0')
  {
    //Runs between A and Z and a and z (will kick out when you find a a non alphabetical character)
    while(((currChar >= 'A' && currChar <= 'Z' ) || (currChar >= 'a' && currChar <= 'z')))
    {
      strBuffer[bufferIndex] = currChar; //Writes the current char to a buffer for later user
      bufferIndex++;
      charIndex++;
      currChar = argv[1][charIndex];//Assigns currChar to the next char in the input string
    }

    //seperator bit
    //Copies the string in the buffer into the array of strings (STILL NEEDS TO BE SORTED)
      if(*strBuffer!= '\0') //Checks to make sure strBuffer is not empty so there are no errors with strcpy
      {
        strncpy(sepArray[sepArrayIndex], strBuffer, strlen(strBuffer));
        wordCount++;
        sepArrayIndex++;
      }
      //Clear strBuffer
      memset(strBuffer, '\0', strlen(argv[1]));
      //Skips the non alphabetical letter
      if(currChar != '\0')
      {
        charIndex++;
      }
      bufferIndex = 0;//reset buffer index
      currChar = argv[1][charIndex]; //assigns the next character to the character AFTER the delimiter
  }

  char* tempStr = malloc(strlen(argv[1]));//allocating memory for a string temporary string variable
  //basic sorting algorithm compares string j and j+1 and swaps them if j is greater than j+1
  //therefor moving strings alphabetical to the front of the list.
  for(i = 0; i< wordCount; i++)
    for(j = 0; j<wordCount-1;j++)
      {
        if(strcmp(sepArray[j], sepArray[j+1]) > 0)
        {
          strcpy(tempStr, sepArray[j]);
          strcpy(sepArray[j],sepArray[j+1]);
          strcpy(sepArray[j+1],tempStr);
        }
      }

//print final list.
 for(i =0; i<wordCount; i++)
  {
    printf("%s \n",sepArray[i]);
  }

  return 0;
}
