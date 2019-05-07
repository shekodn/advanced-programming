#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ftpr = NULL;

    char sArrHash[1000][1000], sAux[2000], *sPlace, sAuxWord[30], cAux;

    size_t len;

    int iA = 11, iB = 0, iArrRep[50], iThing = -1, iNumHash = 0;

    memset(sAuxWord,0,sizeof(sAuxWord));

    ftpr = fopen("Museum.html","r");

    if(ftpr == NULL)
    {
        printf("Couldn´t open file");
        return 0;
    }

    while(ftpr != NULL && fgets(sAux,2000,ftpr) != NULL)
    {
        while(strstr(sAux,"<s>#</s>") != NULL)
        {
            sPlace = strstr(sAux,"<s>#</s>");
            while (sPlace[iA] != '<' && sPlace[iA + 1] != '/' && sPlace[iA + 2] != 'b' && sPlace[iA + 3] != '>')
            {
                cAux = sPlace[iA];
                len = strlen(sAuxWord);
                sAuxWord[len++] = cAux;
                sAuxWord[len] = '\0';
                iA++;
            }
            for(iB = 0; iB < iA; iB++)
            {
                memmove(&sPlace[iB], &sPlace[iB + 1], strlen(sPlace) - iB);
            }
            iA = 11;

            for(iB = 0; iB < 50; iB++)
            {
                if(strcmp(sAuxWord,sArrHash[iB]) == 0)
                {
                    iThing = iB;
                    break;
                }
            }

            if(iThing != -1)
            {
                iArrRep[iThing] += 1;
            }
            else
            {
                strcpy(sArrHash[iNumHash],sAuxWord);
                iArrRep[iNumHash] = 1;
                iNumHash++;
            }

            iThing = -1;


            memset(sAuxWord,0,sizeof(sAuxWord));
        }

    }

    printf("This are the most important hashtags of the Museum: \n");

    for(iB = 0; iB < iNumHash; iB++)
    {
        printf("%d %s %d\n",iB + 1,sArrHash[iB],iArrRep[iB]);
    }

    fclose(ftpr);
    return 0;
}
