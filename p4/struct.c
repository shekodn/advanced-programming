#include <stdio.h>
#include <string.h>

struct Agent {
  char name[100];
  char lname[100];
  char gender[100];
  int age;
  char mission[100];
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

  printf("Enter name: ");
  scanf("%s",&cName);

  printf("Enter last name: ");
  scanf("%s",&cLastName);

  printf("Enter gender: ");
  scanf("%s",&cGender);

  printf("Enter mission: ");
  scanf("%s\n",&cMission);

  printf("Enter age: ");
  iAge = iCout();


  struct Agent agent;

  strncpy(agent.name, cName, iBufferSize);
  strncpy(agent.lname, cLastName, iBufferSize);
  strncpy(agent.gender, cGender, iBufferSize);
  strncpy(agent.mission, cMission, iBufferSize);
  agent.age = iAge;

  printf("%s\n","");
  printf("%s\n",agent.name);
  printf("%s\n",agent.lname);
  printf("%s\n",agent.gender);
  printf("%s\n",agent.mission);
  printf("%d\n", agent.age);



  return 0;
}
