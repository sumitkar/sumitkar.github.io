#include<stdio.h>

int main()
{
 char nam[20];
 int age;
 printf("Enter Your Name : ");
 scnaf("%s",&nam); 
 printf("Enter Your Age : ");
 scanf("%d",&age);
 printf("\nYour Name is %s ",nam); 
 printf("and your age is %d",age);
 return 0;
}