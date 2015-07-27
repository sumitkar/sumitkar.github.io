#include<stdio.h>
#include<conio.h>
int main()
{
 char nam[20];
 int age;
 printf("Enter Your Name : ");
 scanf("%s",&nam); 
 printf("Enter Your Age : ");
 scanf("%d",&age);
 printf("\nUser Name is %s",nam); 
 printf("\nAnd %s age is %d",nam,age);
 getch();
 return 0;
}