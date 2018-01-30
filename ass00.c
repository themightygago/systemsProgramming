#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char ** argv)
{
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
  //Clears the memory allocated above so theres not random shit
  memset(strBuffer, '\0', strlen(argv[1]));
  //Array of seperated strings from the input
  char** sepArray = malloc(strlen(argv[1])*sizeof(char*));
  //clearing all parts of the 2d array with memset
  for(i = 0; i< strlen(argv[1]); i++)
  {
    sepArray[i] = malloc(strlen(argv[1]));
    memset(sepArray[i], '\0', strlen(argv[1]));
  }

  //Array of sorted strings from sepArray
  char** sortedArray = malloc(strlen(argv[1])*sizeof(char*));
  //clearing all parts of the 2d array with memset
  for(i = 0; i< strlen(argv[1]); i++)
  {
    sortedArray[i] = malloc(strlen(argv[1]));
    memset(sepArray[i], '\0', strlen(argv[1]));
  }

  //printf("Length of strlen = %d \n", strlen(argv[1]));//TEST CODE
  //printf("after memory allocated ");


  currChar = argv[1][charIndex];

  //Runs to the end of the input string
  while(currChar!= '\0')
  {
    //printf("currect character = %c \n",currChar);//TEST CODE

    //Runs between A and Z and a and z (will kick out when you find a a non alphabetical character)
    while(((currChar >= 'A' && currChar <= 'Z' ) || (currChar >= 'a' && currChar <= 'z')))
    {
      //printf("%c \n",currChar);//TEST CODE TAKE OUT LATER
      strBuffer[bufferIndex] = currChar;
      //printf("String buffer =%s \n", strBuffer);//TEST CODE
      bufferIndex++;
      charIndex++;
      currChar = argv[1][charIndex];
      strBuffer[bufferIndex] = '\0';
    }

    //seperator bit
    //Copies the string in the buffer into the array of strings (STILL NEEDS TO BE SORTED)
    //printf("String buffer = %s", strBuffer);//TEST CODE

      //printf("String buffer before it's copied:%s\n",strBuffer);//more test code
      if(*strBuffer!= '\0')
      {
        strncpy(sepArray[sepArrayIndex], strBuffer, strlen(strBuffer));
        wordCount++;
        sepArrayIndex++;
        //strcpy(sepArray[sepArrayIndex], strBuffer);
      }
      //Clear strBuffer
      memset(strBuffer, '\0', strlen(argv[1]));
      //Skips the non alphabetical letter
      if(currChar != '\0')
      {
        charIndex++;
      }
      bufferIndex = 0;
      //printf("%c is current character after loops \n", currChar);
      currChar = argv[1][charIndex];
      //printf("%i is wordcount \n", wordCount);
  }

  char* tempStr = malloc(strlen(argv[1]));
  for(i = 0; i< wordCount; i++)
    for(j = 0; j<wordCount-1;j++)
      {
        if(strcmp(sepArray[j], sepArray[j+1]) > 0)
        {
        //  memset(tempStr, '\0', strlen(argv[1]));
          strcpy(tempStr, sepArray[j]);
        //  memset(sepArray[j], '\0', strlen(argv[1]));
          strcpy(sepArray[j],sepArray[j+1]);
        //  memset(sepArray[j+1], '\0', strlen(argv[1]));
          strcpy(sepArray[j+1],tempStr);
        }
      }



 for(i =0; i<wordCount; i++)
  {
    printf("%s \n",sepArray[i]);
  }

  return 0;
}
