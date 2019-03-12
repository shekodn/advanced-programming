#include <stdio.h>
#include <string.h>

union U
{
    int iI;
    float fF;
    int cC;

};

struct Agent {
  char name[100];
  char lname[100];
  char gender[100];
  int age;
  char mission[100];
  union U wildcard;
};

int iCout() {
  // The user will let you know how many numbers he/she wants from it.
  char cInput[100];
  int iOutput = 0;
  int iJ;
  int iLength;

  printf("Enter an Int: ");
  gets(cInput);

  iLength = strlen(cInput);
  for(int iI =0; iI < iLength; iI++)
  {
    iOutput = iOutput * 10 + ( cInput[iI] - '0');
  }

  return iOutput;
}


int main(void) {

  int iBufferSize = 100;

  char cName[100];
  char cLastName[100];
  char cGender[2];
  int iAge;
  char cMission[100];
  union U uWildcard;

  printf("Enter name: ");
  scanf("%s",&cName);

  printf("Enter last name: ");
  scanf("%s",&cLastName);

  printf("Enter gender: ");
  scanf("%s",&cGender);

  printf("Enter mission: ");
  scanf("%s\n",&cMission);

  // printf("Enter age: \n");
  // iAge = iCout();
  // printf("\n");

  printf("Enter union: ");
  scanf("%s\n",&uWildcard);

  struct Agent agent;

  strncpy(agent.name, cName, iBufferSize);
  strncpy(agent.lname, cLastName, iBufferSize);
  strncpy(agent.gender, cGender, iBufferSize);
  strncpy(agent.mission, cMission, iBufferSize);
  // agent.age = iAge;
  agent.wildcard = uWildcard;

  printf("       Name: %s\n",agent.name);
  printf("  Last Name: %s\n",agent.lname);
  printf("     Gender: %s\n",agent.gender);
  printf("    Mission: %s\n",agent.mission);
  // printf("%d\n", agent.age);

  printf(" Union char: %c\n", agent.wildcard.cC);
  printf("  Union int: %d\n", agent.wildcard.iI);
  printf("Union float: %f\n", agent.wildcard.fF);

  return 0;
}
