#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int LetterToNumber(char strSenctence[30])
{
    char *strWord = strtok(strSenctence," ");

    int iNumber = 0;
    while(strWord)
    {

        if (strcmp(strWord, "one") == 0)
        {
            iNumber += 1;
        }
        else if (strcmp(strWord, "two") == 0)
        {
            iNumber += 2;
        }
        else if (strcmp(strWord, "three") == 0)
        {
            iNumber += 3;
        }
        else if (strcmp(strWord, "four") == 0)
        {
            iNumber += 4;
        }
        else if (strcmp(strWord, "five") == 0)
        {
            iNumber += 5;
        }
        else if (strcmp(strWord, "six") == 0)
        {
            iNumber += 6;
        }
        else if (strcmp(strWord, "seven") == 0)
        {
            iNumber += 7;
        }
        else if (strcmp(strWord, "eight") == 0)
        {
            iNumber += 8;
        }
        else if (strcmp(strWord, "nine") == 0)
        {
            iNumber += 9;
        }
        else if (strcmp(strWord, "ten") == 0)
        {
            iNumber += 10;
        }
        else if (strcmp(strWord, "eleven") == 0)
        {
            iNumber += 11;
        }
        else if (strcmp(strWord, "twelve") == 0)
        {
            iNumber += 12;
        }
        else if (strcmp(strWord, "thirteen") == 0)
        {
            iNumber += 13;
        }
        else if (strcmp(strWord, "fourteen") == 0)
        {
            iNumber += 14;
        }
        else if (strcmp(strWord, "fifteen") == 0)
        {
            iNumber += 15;
        }
        else if (strcmp(strWord, "sixteen") == 0)
        {
            iNumber += 16;
        }
        else if (strcmp(strWord, "seventeen") == 0)
        {
            iNumber += 17;
        }
        else if (strcmp(strWord, "eighteen") == 0)
        {
            iNumber += 18;
        }
        else if (strcmp(strWord, "nineteen") == 0)
        {
            iNumber += 19;
        }
        else if (strcmp(strWord, "twenty") == 0)
        {
            iNumber += 20;
        }
        else if (strcmp(strWord, "thirty") == 0)
        {
            iNumber += 30;
        }
        else if (strcmp(strWord, "fourty") == 0)
        {
            iNumber += 40;
        }
        else if (strcmp(strWord, "fifty") == 0)
        {
            iNumber += 50;
        }
        else if (strcmp(strWord, "sixty") == 0)
        {
            iNumber += 60;
        }
        else if (strcmp(strWord, "seventy") == 0)
        {
            iNumber += 70;
        }
        else if (strcmp(strWord, "eighty") == 0)
        {
            iNumber += 80;
        }
        else if (strcmp(strWord, "ninety") == 0)
        {
            iNumber += 90;
        }
        else if (strcmp(strWord, "hundred") == 0)
        {
            iNumber *= 100;
        }
        strWord = strtok (NULL, " ");
    }

    return iNumber;
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
    char strChars[3] = {'a','a','a'}, strNumber[3], strSenctence[30], strNumberFinal[9], strFinal[12] = {};
    int iA = 0, iTemp = 0, iNumber = 0, iNumsOfChars = 0;
    int c;

    printf("Agent Id Validation.\n");

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


    //It erases the stdin
    do
    {
        c = getchar();
    }
    while(c != EOF && c != '\n');

    while(iNumsOfChars < 9)
    {
        printf("Insert Number: \n");
        fgets(strSenctence, 30, stdin);
        strSenctence[strlen(strSenctence) - 1] = '\0';
        iNumber = LetterToNumber(strSenctence);
        if(iNumsOfChars + HowManyChars(iNumber) > 9)
        {
            printf("You already have too many numbers!!\n");
            continue;
        }
        iNumsOfChars += HowManyChars(iNumber);
        sprintf(strNumber, "%d", iNumber);
        strcat(strNumberFinal, strNumber);

    }

    vRandomize(strNumberFinal,9);

    strcat(strFinal,strNumberFinal);

    printf("Id: %s \n",strFinal);


    return 0;
}
