#include<stdio.h>
int main()
{
 int num,r,c;
 printf("Enter number of rows/columns: ");
 scanf("%d",&num);
 for(r=1; r<=num; r++)
 {
  for(c=1; c<=num; c++)
     printf("* ");
  printf("\n");
 }
 getch();
 return 0;
}