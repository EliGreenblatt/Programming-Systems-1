#include <stdio.h>
#include "NumClass.h"

int main()
{
  int num1 = 0;
  int num2 = 0;

  scanf("%d",&num1);
  scanf("%d",&num2);
  
  printf("The Armstrong numbers are:");
  for (int i = num1; i < num2; i++)
  {
    int x = 0;
    x = isArmstrong(i);
    if(x == 1)
    {
      printf(" %d", i);
    }
  }
  printf("\nThe Palindromes are:");

  for (int i = num1; i < num2; i++)
  {
    int x = isPalindrome(i);
    if (x == 1)
    {
      printf(" %d", i);
    }
    
  }

  printf("\nThe Prime numbers are:");
  for (int i = num1; i < num2; i++)
  {
    if(isPrime(i) == 1)
    {
      printf(" %d", i);
    }
  }

 printf("\nThe Strong numbers are:");
  for (int i = num1; i < num2; i++)
  {
    if(isStrong(i) == 1)
    {
      printf(" %d", i);
    }
  }

  printf("\n");

  return 1;
}