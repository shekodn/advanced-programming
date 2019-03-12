#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char LetterToNumber(char strSentence[50])
{
    char *strInput = strtok(strSentence," ");
a    while(strInput)
    {

        if (strcmp(strInput, "one") == 0)
        {
            return "1";
        }
        else if (strcmp(strInput, "two") == 0)
        {
            return "2";
        }
        else if (strcmp(strInput, "three") == 0)
        {
            return "3";
        }
        else if (strcmp(strInput, "four") == 0)
        {
            return "4";
        }
        else if (strcmp(strInput, "five") == 0)
        {
            return "5";
        }
        else if (strcmp(strInput, "six") == 0)
        {
            return "6";
        }
        else if (strcmp(strInput, "seven") == 0)
        {
            return "7";
        }
        else if (strcmp(strInput, "eight") == 0)
        {
            return "8";
        }
        else if (strcmp(strInput, "nine") == 0)
        {
            return "9";
        } else {
          return "-1";
        }
        // else if (strcmp(strInput, "ten") == 0)
        // {
        //     iNumber += 10;
        // }
        // else if (strcmp(strInput, "eleven") == 0)
        // {
        //     iNumber += 11;
        // }
        // else if (strcmp(strInput, "twelve") == 0)
        // {
        //     iNumber += 12;
        // }
        // else if (strcmp(strInput, "thirteen") == 0)
        // {
        //     iNumber += 13;
        // }
        // else if (strcmp(strInput, "fourteen") == 0)
        // {
        //     iNumber += 14;
        // }
        // else if (strcmp(strInput, "fifteen") == 0)
        // {
        //     iNumber += 15;
        // }
        // else if (strcmp(strInput, "sixteen") == 0)
        // {
        //     iNumber += 16;
        // }
        // else if (strcmp(strInput, "seventeen") == 0)
        // {
        //     iNumber += 17;
        // }
        // else if (strcmp(strInput, "eighteen") == 0)
        // {
        //     iNumber += 18;
        // }
        // else if (strcmp(strInput, "nineteen") == 0)
        // {
        //     iNumber += 19;
        // }
        // else if (strcmp(strInput, "twenty") == 0)
        // {
        //     iNumber += 20;
        // }
        // else if (strcmp(strInput, "thirty") == 0)
        // {
        //     iNumber += 50;
        // }
        // else if (strcmp(strInput, "fourty") == 0)
        // {
        //     iNumber += 40;
        // }
        // else if (strcmp(strInput, "fifty") == 0)
        // {
        //     iNumber += 50;
        // }
        // else if (strcmp(strInput, "sixty") == 0)
        // {
        //     iNumber += 60;
        // }
        // else if (strcmp(strInput, "seventy") == 0)
        // {
        //     iNumber += 70;
        // }
        // else if (strcmp(strInput, "eighty") == 0)
        // {
        //     iNumber += 80;
        // }
        // else if (strcmp(strInput, "ninety") == 0)
        // {
        //     iNumber += 90;
        // }
        // else if (strcmp(strInput, "hundred") == 0)
        // {
        //     iNumber *= 100;
        // }
        // strInput = strtok (NULL, " ");
    }
}

int HowManyChars(int iNumber)
{
    if(iNumber > 100)
    {
        return 3;
    }
    else if(iNumber < 99 && iNumber > 9)
    {
        return 2;
    }
    else
    {
        return 1;
    }
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


int main()
{
    char strChars[3] = {'a','b','c'};
    char strNumber[3];
    char strSentence[50];
    char strNumberFinal[9];
    char strFinal[12] = {};
    int iI = 0;
    int iTemp = 0;
    int iNumber = 0;
    int iNumsOfChars = 0;
    int c;

    for(iI = 0; iI < 3; iI++)
    {
      printf("Give me the %d character: ",iI);
      scanf("%c",&strChars[iI]);
      if(!isalpha(strChars[iI]))
      {
        while(!isalpha(strChars[iI]))
        {
            printf("Thats not a letter\n");
            scanf(" %c",&strChars[iI]);
        }
      }
    }

    printf("%s\n", strChars);


    for(iI = 0; iI < 3; iI++)
    {
        strFinal[iI] = strChars[iI];
    }

    printf("%s\n", strFinal);

    ///

    for(iI = 0; iI < 9; iI++)
    {
      printf("Give me a number in words (eg. one): ",iI);

      char strInput[12] = {};
      scanf("%s",strInput);

      if (LetterToNumber(strInput) == -1 ) {
        while (LetterToNumber(strInput) == -1){
          printf("Invalid number \n");
          scanf("%s",strInput);
        }
      }

      char chTemp[3] = LetterToNumber(iI);
      strFinal[iI] = chTemp;
      printf("%c\n", strFinal[iI]);


      // if (strFinal !=)
      //
      // if(!isalpha(strNumber[iI]))
      // {
      //   while(!isalpha(strChars[iI]))
      //   {
      //       printf("Thats not a letter\n");
      //       scanf(" %c",&strNumber[iI]);
      //   }
      // }
    }

    // while(c != EOF && c != '\n')
    // {
    //
    // }

    // do
    // {
    //     c = getchar();
    //     printf("You entered %c\n", c);
    // }
    // while(c != EOF && c != '\n');

    // while(iNumsOfChars < 9)
    // {
    //     printf("\nInsert Number: \n");
    //     fgets(strSentence, 50, stdin);
    //     strSentence[strlen(strSentence) - 1] = '\0';
    //     iNumber = LetterToNumber(strSentence);
    //     if(iNumsOfChars + HowManyChars(iNumber) > 9)
    //     {
    //         printf("Error: Too many numbers \n");
    //         continue;
    //     }
    //     // iNumsOfChars += HowManyChars(iNumber);
    //     iNumsOfChars += 1;
    //     sprintf(strNumber, "%d", iNumber);
    //     strcat(strNumberFinal, strNumber);
    //
    // }

    // vRandomize(strNumberFinal,9);

    // strcat(strFinal,strNumberFinal);
    //
    // printf("Id: %s \n",strFinal);


    return 0;
}
