#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int wordToNumber() {

  char numbers[10][10] = {"cero", "uno" , "dos", "tres",
                                      "cuatro", "cinco", "seis", "siete",
                                     "ocho", "nueve", "cien"};

  char input[100], word[10], *ptr, *tmp;
  int i, value = 0, len;

  /* get the number in words from user */
  printf("Enter number in word:\n");
  fgets(input, 100, stdin);
  input[strlen(input) - 1] = '\0';

  tmp = input;
  /* move pointer to the space to extract word by word */
  ptr = strchr(tmp, ' ');
  if (ptr != NULL) {
          len = ptr - tmp;
          strncpy(word, tmp, len);
          word[len] = '\0';
          tmp = ptr + 1;
  } else {
          /* last word in the given string */
          len = strlen(tmp);
          strncpy(word, tmp, len);
          word[len] = '\0';
  }

  for (i = 0; i < 10; i++) {
          /* word to number conversion */
          if (strcasecmp(word, numbers[i]) == 0) {
                  value = (value * 10) + i;
                  break;
          }
  }

  /* print the number */
  // printf("Value in number is %d\n", value);

  return value;

}

void vSwap(char *CharA, char *CharB)
{
    char iTemp = *CharA;
    *CharA = *CharB;
    *CharB = iTemp;
}


void vRandomize(char iArr[], int iNum)
{
    int iA;

    srand( time(NULL));
    for(iA = (iNum - 1); iA > 0; iA--)
    {
        int iB = rand() % (iA + 1);
        vSwap(&iArr[iA], &iArr[iB]);
    }
}


int main() {

  int iCounter = 0;
  int iTreshhold = 9;
  char strChars[3] = {'a','a','a'};
  char strNumbers[9] = {0,0,0,0,0,0,0,0,0};
  char strRandNumbers[9] = {0,0,0,0,0,0,0,0,0};
  int iCurrentNumber = 0;
  // char strFinal[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  char strFinal[12] = {};
  int iA = 0;

  for(iA = 0; iA < 3; iA++)
  {
      printf("Give me the %d character: ",iA);
      scanf(" %c",&strChars[iA]);
      if(!isalpha(strChars[iA]))
      {
          while(!isalpha(strChars[iA]))
          {
              printf("Thats not a letter!!!!\n");
              printf("Give me the %d character: ",iA);
              scanf(" %c",&strChars[iA]);
          }
      }
  }

  for(iA = 0; iA < 3; iA++)
  {
      strFinal[iA] = strChars[iA];
  }

  while (iCounter < iTreshhold) {
    iCurrentNumber = wordToNumber();
    if(iCurrentNumber <= 0) {
      printf("PUT A VALID NUMBER\n");
    }
    strNumbers[iCounter] = iCurrentNumber +'0';
    iCounter++;
  }
  // printf("Your number: \n");
  // printf("%s \n", strNumbers);

  // printf("Your random number: \n");
  vRandomize(strNumbers,9);
  // printf("%s \n", strNumbers);

  // strcat(strFinal, strChars);

  // printf("ID: %s\n",strFinal);

  strcat(strFinal,strNumbers);

  printf("ID: %s\n",strFinal);


  return 0;




}
