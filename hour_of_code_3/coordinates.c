#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fPtr1 = NULL;
    FILE *fPtr2 = NULL;
    FILE *fPtr3 = NULL;

    char cWord1[20], cWord2[20], sLat[20], sLong[20], sArrLat[1000][20], sArrLong[1000][20];

    double dLat, dLong, dArrLat[1000], dArrLon[1000];

    int iLine = 0;

    fPtr1 = fopen("coordinates", "r");
    fPtr2 = fopen("file1.txt","w");
    fPtr3 = fopen("file2.txt","w");

    if(fPtr1 == NULL || fPtr2 == NULL || fPtr3 == NULL)
    {
        printf("File Error");
        return 0;
    }

    while (fscanf(fPtr1, "%s %s %lf %s %s %lf", cWord1, sLat, &dLat, cWord2, sLong, &dLong) != EOF)
    {
        switch(sLat[strlen(sLat) - 1])
        {
            case 'N':
                strcat(sLat,"orth");
                break;
            case 'S':
                strcat(sLat,"outh");
                break;
            case 'E':
                strcat(sLat,"ast");
                break;
            case 'W':
                strcat(sLat,"est");
                break;
            default:
                break;
        }

        switch(sLong[strlen(sLong) - 1])
        {
            case 'N':
                strcat(sLong,"orth");
                break;
            case 'S':
                strcat(sLong,"outh");
                break;
            case 'E':
                strcat(sLong,"ast");
                break;
            case 'W':
                strcat(sLong,"est");
                break;
            default:
                break;
        }

        dArrLat[iLine] = dLat;
        dArrLon[iLine] = dLong;
        strcpy(sArrLat[iLine],sLat);
        strcpy(sArrLong[iLine],sLong);
        iLine++;
    }

    int iCount1, iCount2;
    double dSwapLat, dSwapLong;
    char sSwapLat[20], sSwapLong[20];
    for(iCount1 = 0; iCount1 < (iLine - 1); iCount1++)
    {
        for(iCount2 = 0; iCount2 < iLine - iCount1 - 1; iCount2++)
        {
            if(dArrLat[iCount2] != dArrLat[iCount2 + 1])
            {
                if(dArrLat[iCount2] > dArrLat[iCount2 + 1])
                {
                    dSwapLat = dArrLat[iCount2];
                    dSwapLong = dArrLon[iCount2];
                    strcpy(sSwapLat,sArrLat[iCount2]);
                    strcpy(sSwapLong,sArrLong[iCount2]);

                    dArrLat[iCount2] = dArrLat[iCount2 + 1];
                    dArrLon[iCount2] = dArrLon[iCount2 + 1];
                    strcpy(sArrLat[iCount2],sArrLat[iCount2 + 1]);
                    strcpy(sArrLong[iCount2],sArrLong[iCount2 + 1]);

                    dArrLat[iCount2 + 1] = dSwapLat;
                    dArrLon[iCount2 + 1] = dSwapLong;
                    strcpy(sArrLat[iCount2 + 1],sSwapLat);
                    strcpy(sArrLong[iCount2 + 1],sSwapLong);
                }

            }
            else
            {
                if(dArrLon[iCount2] > dArrLon[iCount2 + 1])
                {
                    dSwapLat = dArrLat[iCount2];
                    dSwapLong = dArrLon[iCount2];
                    strcpy(sSwapLat,sArrLat[iCount2]);
                    strcpy(sSwapLong,sArrLong[iCount2]);

                    dArrLat[iCount2] = dArrLat[iCount2 + 1];
                    dArrLon[iCount2] = dArrLon[iCount2 + 1];
                    strcpy(sArrLat[iCount2],sArrLat[iCount2 + 1]);
                    strcpy(sArrLong[iCount2],sArrLong[iCount2 + 1]);

                    dArrLat[iCount2 + 1] = dSwapLat;
                    dArrLon[iCount2 + 1] = dSwapLong;
                    strcpy(sArrLat[iCount2 + 1],sSwapLat);
                    strcpy(sArrLong[iCount2 + 1],sSwapLong);
                }
            }
        }
    }


    int iCount3;
    for(iCount3 = 0; iCount3 < iLine; iCount3++)
    {
        fprintf(fPtr2,"%s\t%s\n",sArrLat[iCount3],sArrLong[iCount3]);
        fprintf(fPtr3,"%0.8f\t%0.8f\n",dArrLat[iCount3], dArrLon[iCount3]);
    }

    printf("Done\n");

    fclose(fPtr1);
    fclose(fPtr2);
    fclose(fPtr3);

    return 0;

}
