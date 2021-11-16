#include<stdio.h>
int main()
{
  int a=1;
  char *find;
  find=(char*)&a;
  if(*find)
    printf("little endian\n");
  else
    printf("big endian\n");
  return 0;
}
