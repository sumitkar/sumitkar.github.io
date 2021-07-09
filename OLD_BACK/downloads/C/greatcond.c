#include<stdio.h>
void main()
{
 int n1,n2,g;
 printf("Enter Numbers (n1, n2) : ");
 scanf("%d %d",&n1,&n2);
 g=n1>n2?n1:n2;
 printf("Greatest=%d",g);
}