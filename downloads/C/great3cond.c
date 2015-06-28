#include<stdio.h>

void main()
{
 int n1,n2,n3;
 printf("Enter Numbers (n1, n2, n3) : ");
 scanf("%d %d %d",&n1,&n2,&n3);
 printf("Greatest= %d",n1>n2?n1>n3?n1:n3:n2>n3?n2:n3);
}