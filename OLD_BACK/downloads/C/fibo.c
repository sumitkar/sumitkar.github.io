#include<stdio.h>

void main() 
{
 int t,i,m=0,n=1,f=1; 
 printf("\n\nEnter the number of terms:");
 scanf("%d",&t); 
 printf("\n The Fibonacci Series of %d terms:\n",t);
 for(i=1;i<=t;i++)
  {
   printf("%d\t",f);
   f=m+n;
   m=n;
   n=f;
  }
}
