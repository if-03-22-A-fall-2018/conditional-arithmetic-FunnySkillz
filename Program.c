#include <stdio.h>
#include "functions.h"
#include <limits.h>

int main(int argc, char const *argv[]) {
  ChooseFunction();
  return 0;
}
void ChooseFunction()
{
  int functionNumber;
  long number;
  printf("Choose a function\n");
  printf("1.Add\n2.Multiply\n");
  scanf("%d",&functionNumber);
  switch (functionNumber) {
    case 1:printf("Result is %ld\n", Add(&number));
    break;
    case 2:printf("Result is %ld\n", Multiply(&number));
    break;
    default:
    printf("Error! Invalid input, please try again.\n");
    ChooseFunction();
    break;
  }
}

int GetNumber(int* number)
{
  int temp = 0;
  printf("Select a number in the range (1-100): ");
  scanf("%i",&temp);
  if (temp < 1 || temp > 100) {
    printf("Invalid input, try again!\n");
    GetNumber(number);
  }
  number = &temp;
  return *number;
}

long Add(int *number)
{
  *number = GetNumber(number);
  long result = 0;
  printf("%d\n",*number );
  for (int i = 3; i <= *number; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        result += i;
    }
  }

  return result;
}

long Multiply(int *number)
{
  *number = GetNumber(number);
  long result = 0;
  for (int i = 3; i <= *number; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        result *= i;
    }
  }
  return result;
}

long isOverflow(long max){
  long result = LONG_MAX;
  for(long i = max; i > 3; i--)
  {
    if((i % 3 == 0) || ( i % 5 == 0))
    {
      result /= i;
    }
  }

  if(result >= 3)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
