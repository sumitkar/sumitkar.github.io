#include<stdio.h>

void main()
{
 int x=1,num,res;
 printf("Enter a Number : ");
 scanf("%d",&num);
 while(x<=10)
 {
   res=num*x;
   printf("\n%d x %d = %d",num,x,res);
   x++;
 } 
}