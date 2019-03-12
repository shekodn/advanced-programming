// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexVal[])
{
    int iLen = strlen(hexVal);
    int iBase = 1;
    int iDecimalValue = 0;

    for (int i = iLen-1; i >= 0; i--)
    {
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            iDecimalValue += (hexVal[i] - 48) * iBase;
            iBase = iBase * 16;
        }

        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
        {
            iDecimalValue += (hexVal[i] - 55) * iBase;
            iBase = iBase * 16;
        }
    }

    return iDecimalValue;
}

int main()
{
  char hexNum[50];

  while(1==1)
  {
    printf("Decimal: ");
    scanf("%s",hexNum);
    printf("%d\n", hexadecimalToDecimal(hexNum));
  }
}
