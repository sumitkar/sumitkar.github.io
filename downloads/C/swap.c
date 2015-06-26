#include<stdio.h>

void main()
{
 int x,y,z;
 printf("Enter Values x and y : ");
 scnaf("%d%d",&x,&y);
 z=y;
 y=x;
 x=z;
 printf("\nValue of x=%d",x);
 printf("\nValue of y=%d",y);
}
