#include<stdio.h>
void main()
{
 int x,y,z;
 printf("Enter values of x, y and z : ");
 scanf("%d,%d,%d",&x,&y,&z);
 if(x>=y && x>=z)
   printf("\n%d is greatest",x);
 else if(y>=z)
   printf("\n%d is greatest",y);
 else
   printf("\n%d is greatest",z);
}