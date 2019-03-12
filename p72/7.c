#include <stdio.h>
#include <string.h>

union miUnion
{
    int iI;
    char cC;
    char str[200];
};

struct Agent {
  char name[200];
  char lname[200];
  char gender[200];
  int age;
  char mission[200];
  union miUnion uU;
};

int main(void) {

  char cName[200];
  char cLastName[200];
  char cGender[2];
  char cMission[200];

  union miUnion uU;
  struct Agent agent;

  printf("Enter union: ");
  scanf("%s\n",&uU);

  agent.uU = uU;

  printf("  Union int: %d\n", agent.uU.iI);
  printf("Union str: %s\n", agent.uU.str);
  printf(" Union char: %c\n", agent.uU.cC);

  return 0;
}
