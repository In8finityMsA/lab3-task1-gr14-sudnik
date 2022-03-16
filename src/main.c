/* hello.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int HasRepDigits(int number)
{
  int array[10];
  memset(array, 0, sizeof(int) * 10);
  while(number != 0){
    array[number%10]++;
    number/=10;
  }
  for(int i = 0; i < 9; i++){
    if(array[i] > 1){
      return 1;
    }
  }
  return 0;
}

int CountRepDigitsInArray(int* array, int n)
{
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    if(HasRepDigits(array[i])){
      count++;
    }
  }
  return count;
}

int main (void)
{
  int n = 0;
  scanf("%d", &n);
  if(n <= 0)
  {
    printf("Bad input task failed.\n");
    return -1;
  }
  srand(time(0));
  int* numbers = malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++)
  {
    numbers[i] = rand() % 1000;
    printf("%d\n", numbers[i]);
  }
  int count = CountRepDigitsInArray(numbers, n);
  printf("%d\n", count);
  return 0;
}
