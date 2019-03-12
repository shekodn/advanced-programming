/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="one hundred thirty eight";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  int number = 0;
  while (pch != NULL)
  {
    if (strcmp(pch, "one") == 0)
    {
      number += 1;
    }
    else if (strcmp(pch, "two") == 0)
    {
      number += 2;
    }
    else if (strcmp(pch, "three") == 0)
    {
      number += 3;
    }
    else if (strcmp(pch, "four") == 0)
    {
      number += 4;
    }
    else if (strcmp(pch, "five") == 0)
    {
      number += 5;
    }
    else if (strcmp(pch, "six") == 0)
    {
      number += 6;
    }
    else if (strcmp(pch, "seven") == 0)
    {
      number += 7;
    }
    else if (strcmp(pch, "eight") == 0)
    {
      number += 8;
    }
    else if (strcmp(pch, "nine") == 0)
    {
      number += 9;
    }
    else if (strcmp(pch, "ten") == 0)
    {
      number += 10;
    }
    else if (strcmp(pch, "eleven") == 0)
    {
      number += 11;
    }
    else if (strcmp(pch, "twelve") == 0)
    {
      number += 12;
    }
    else if (strcmp(pch, "thirteen") == 0)
    {
      number += 13;
    }
    else if (strcmp(pch, "fourteen") == 0)
    {
      number += 14;
    }
    else if (strcmp(pch, "fifteen") == 0)
    {
      number += 15;
    }
    else if (strcmp(pch, "sixteen") == 0)
    {
      number += 16;
    }
    else if (strcmp(pch, "seventeen") == 0)
    {
      number += 17;
    }
    else if (strcmp(pch, "eighteen") == 0)
    {
      number += 18;
    }
    else if (strcmp(pch, "nineteen") == 0)
    {
      number += 19;
    }
    else if (strcmp(pch, "twenty") == 0)
    {
      number += 20;
    }
    else if (strcmp(pch, "thirty") == 0)
    {
      number += 30;
    }
    else if (strcmp(pch, "fourty") == 0)
    {
      number += 40;
    }
    else if (strcmp(pch, "fifty") == 0)
    {
      number += 50;
    }
    else if (strcmp(pch, "sixty") == 0)
    {
      number += 60;
    }
    else if (strcmp(pch, "seventy") == 0)
    {
      number += 70;
    }
    else if (strcmp(pch, "eighty") == 0)
    {
      number += 80;
    }
    else if (strcmp(pch, "ninety") == 0)
    {
      number += 90;
    }
    else if (strcmp(pch, "hundred") == 0)
    {
      number *= 100;
    }

    pch = strtok (NULL, " ");
  }

  printf("%d\n", number);
  return 0;
}
