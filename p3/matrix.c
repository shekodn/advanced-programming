#include <stdio.h>

int main()
{
   int iM, iN, iC, iD, matA[10][10], matB[10][10], matAnswer[10][10];

   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &iM, &iN);
   printf("Enter the elements of matA matrix\n");

   for (iC = 0; iC < iM; iC++)
      for (iD = 0; iD < iN; iD++)
         scanf("%d", &matA[iC][iD]);

   printf("Enter the elements of matB matrix\n");

   for (iC = 0; iC < iM; iC++)
      for (iD = 0 ; iD < iN; iD++)
         scanf("%d", &matB[iC][iD]);

   printf("Sum of entered matrices:-\n");

   for (iC = 0; iC < iM; iC++) {
      for (iD = 0 ; iD < iN; iD++) {
         matAnswer[iC][iD] = matA[iC][iD] + matB[iC][iD];
         printf("%d\t", matAnswer[iC][iD]);
      }
      printf("\n");
   }

   return 0;
}
