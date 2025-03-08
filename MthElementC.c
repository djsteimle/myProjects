#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char line[1024]; //array to store input// this can be done using dynamic memory allocation as well to save memory
  int m = -1; //m index we need
  int index = -1; //index of m element
  int lIndex = -2; //-2 to account for 0 and ignore \n

  //read inout and store in an array
  fgets(line, sizeof line, stdin); //scanf doesn't work hence reading line from the Test Input file
  //identify the last index of array
  lIndex = strlen(line)+lIndex;
  //convert last indext to int
  //subtract ascii code of 0(48)
  m = line[lIndex] - '0';
  //check if it is in bounds
  //multiplying by 2 to account for space delimiters
  if((m*2)<=lIndex){
   index = (lIndex/2 - m)*2;
   printf("%c\n", line[index]);
//while (line[index] != ' ')
//{
//printf("%c", line[index]);
//index++;
//}
//printf("\n");
  }
  //print blank line otherwise
  else
   printf("\n");

  return 0;
}

