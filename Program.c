#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[]) {
  ChooseFunction();
  return 0;
}
void ChooseFunction()
{
  int functionNumber;

  printf("Choose a function\n");
  printf("1.Add\n2.Multiply\n");
  scanf("%d",&functionNumber);
  switch (functionNumber) {
    case 1:printf("Result is %ld\n",Add(functionNumber));
    break;
    case 2:printf("Result is %ld\n",Multiply(functionNumber));
    break;
    default:
    printf("Error! Invalid input, please try again.\n");
    ChooseFunction();
    break;
  }
}
void GetNumber(long *number)
{
  printf("Select a number in the range (1-100): ");
  scanf("%d",number);
  if (*number < 1 || *number > 100) {
    printf("Invalid input, try again!\n");
    GetNumber(number);
  }
}
long Add(long *number)
{
  GetNumber(number);
  for (int i = 1; i < *number; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        number += i;
    }
  }
  return number;
}

long Multiply(int *number)
{
  GetNumber(number);
  long result = 0;
  for (int i = 1; i < *number; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        result*= i;
    }
  }
  return result;
}
