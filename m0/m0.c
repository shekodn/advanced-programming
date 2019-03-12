// Sergio Diaz - A01192313
// Mission #0

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Assets
{
  char name[20];
  char lname[20];
  char id[13];

} Assets;

typedef struct Agent
{
  char name[20];
  char lname[20];
  char gender[10];
  char mission[12];
  int age;
  int assetNumber;
  Assets assets[50];
}Agent;

void PrintInfo(Agent Info[50], int iJ, int iI, int iCont)
{
  for(iJ = 0; iJ < iI; iJ++)
  {
    printf("\n\n\t\tAgent %d\n\n", iJ + 1);
    printf("Name: ");
    printf("%s\n", Info[iJ].name);
    printf("Last Name: ");
    printf("%s\n", Info[iJ].lname);
    printf("Age: ");
    printf("%d\n", Info[iJ].age);
    printf("Gender: ");
    printf("%s\n", Info[iJ].gender);
    printf("Mission: ");
    printf("%s\n", Info[iJ].mission);
    printf("\n\t\tAssets: %d\n\n", Info[iJ].assetNumber);
    for(iCont = 0; iCont < Info[iJ].assetNumber; iCont++)
    {
      printf("Name of Asset: ");
      printf("%s\n", Info[iJ].assets[iCont].name);
      printf("Last Name of Asset: ");
      printf("%s\n", Info[iJ].assets[iCont].lname);
      printf("ID of Asset: ");
      printf("%s\n\n", Info[iJ].assets[iCont].id);
    }
  }
}

int printMenu(){
  int iOption;

  printf("Select the option \n");
  printf("1. Add Agent\n");
  printf("2. Add Assets\n");
  printf("3. See Agents & Assets Information\n");
  printf("4. Delete Agent\n");
  printf("5. Exit\n");
  scanf("%d", &iOption);

  return iOption;
}

// void deleteAgent(){
//
//   // printf("Enter the number of the agent you want to delete\n");
//   // scanf("%d", &position);
//   //
//   // if (position >= n+1)
//   // printf("Deletion not possible.\n");
//   // else
//   // {
//   //   for (c = position - 1; c < n - 1; c++)
//   //   array[c] = array[c+1];
//   //
//   //   printf("Resultant array:\n");
//   //
//   //   for (c = 0; c < n - 1; c++)
//   //   printf("%d\n", array[c]);
//   // }
// }

int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}

// https://stackoverflow.com/questions/48575265/regex-in-c-for-matching
// https://www.quora.com/How-do-I-use-regular-expressions-in-the-C-programming-language
int checksAgentId(char* str){
  const char* reRegex = "^[a-z]{4}[0-9]{9}$";
  return match(str, reRegex) ? 1 : 0;
}

int checksMissionId(char* str){
  const char* reRegex = "^[a-z]{3}[0-9]{9}$";
  return match(str, reRegex) ? 1 : 0;
}


int main()
{
  int iI = 0;
  int iCont;
  int iAddAgent;
  int iOption;
  int iJ;
  Agent Info[50];

  iOption = printMenu();

  while(iOption != 5)
  {
    // Agent
    if(iOption == 1)//Add Agents
    {
      printf("Option %d was selected\n", iOption);

      printf("Name: ");
      scanf("%s",Info[iI].name);
      printf("Last Name: ");
      scanf("%s",Info[iI].lname);
      printf("Age: ");
      scanf("%d",&Info[iI].age);
      printf("Gender: ");
      scanf("%s",Info[iI].gender);
      printf("Mission: ");

      int isValidMission = 0;

      while (isValidMission == 0) {
        printf("Mission: (3 letters and 9 digits)");
        scanf("%s",Info[iI].mission);
        isValidMission = checksMissionId(Info[iI].mission);
      }
      iI++;
    }
    // Assets
    else if(iOption == 2)
    {
      printf("Option %d was selected\n", iOption);

      printf("Select the number of the agent");
      for(iJ = 0; iJ < iI; iJ++)
      {
        printf("\n%d Agent %s\n", iJ + 1, Info[iJ].name);
      }
      scanf("\n%d", &iAddAgent);
      printf("\nNumber of Assets to add: ");
      scanf("%d", &Info[iAddAgent - 1].assetNumber);
      for(iCont = 0; iCont<Info[iAddAgent - 1].assetNumber; iCont++)
      {
        printf("\nName of asset: ");
        scanf("%s",Info[iAddAgent - 1].assets[iCont].name);
        printf("Last name of asset: ");
        scanf("%s",Info[iAddAgent - 1].assets[iCont].lname);

        int isValidAssetId = 0;

        while (isValidAssetId == 0) {
          printf("ID of Asset: (4 letters and 9 digits)");
          scanf("%s",Info[iAddAgent - 1].assets[iCont].id);
          isValidAssetId = checksAgentId(Info[iAddAgent - 1].assets[iCont].id);
        }

      }
    }
    else if(iOption == 3)
    {
      printf("Option %d was selected\n", iOption);
      PrintInfo(Info, iJ, iI, iCont);
    }

    else if(iOption == 4)
    {
      printf("Option %d was selected\n", iOption);
      //delete all assets from that agent
      //delete specific agent
      //deleteAgent(Info, iJ, iI, iCont);

    }

    iOption = printMenu();
  }
  printf("Exit was selected\n", iOption);

  return 0;
}
