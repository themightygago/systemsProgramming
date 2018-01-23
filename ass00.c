#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char** argv)
{
  char currChar;
  //Creates a character array allocated with the size of the input string.
  char* strBuffer = malloc(strlen(argv[1]));

  //Clears the memory allocated above so theres not random shit
  memset(strBuffer, '\0', strlen(argv[1]));

  //Array of seperated strings from the input
  char** sepArray = malloc(strlen(argv[1]));

  for(int i = 0; i< strlen(argv[1]); i++)
  {
    sepArray[i] = malloc(strlen(argv[1]));
    memset(sepArray[i], '\0', strlen(argv[1]));
  }

  //printf("Length of strlen = %d \n", strlen(argv[1]));//TEST CODE
  //printf("after memory allocated ");
  int charIndex = 0;
  int bufferIndex = 0;
  int sepArrayIndex = 0;
  int wordCount =0;

  currChar = argv[1][charIndex];

  //Runs to the end of the input string
  while(currChar!= '\0')
  {
    //printf("currect character = %c \n",currChar);//TEST CODE

    //Runs between A and Z and a and z (will kick out when you find a a non alphabetical character)
    while(((currChar >= 65 && currChar <= 90 ) || (currChar >= 97 && currChar <= 122)))
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

      printf("String buffer before it's copied:%s\n",strBuffer);
      if(*strBuffer!= '\0')
      {
        strncpy(sepArray[sepArrayIndex], strBuffer, strlen(strBuffer));
        wordCount++;
        //strcpy(sepArray[sepArrayIndex], strBuffer);
      }

      sepArrayIndex++;
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
      printf("%i is wordcount \n", wordCount);

  }

  //printf("size of strbuffer array = %d \n", sizeof(strBuffer[0]));
  //printf("size of sep array = %d \n", sizeof(sepArray[0]));


 for(int i =0; i<wordCount; i++)
  {
    printf("%s \n",sepArray[i]);
  }


/*  while( haven't fallen off the input string )
  {
   .. read from input string
   while( haven't found a separator and haven't fallen off the input string )
   {
   .. read from input string
   .. advance to next character
   }
   // either fell off of input string, or found a separator
   if( found a separator )
   {
   .. copy the component string out of the input string
   }
*/
  return 0;
}
