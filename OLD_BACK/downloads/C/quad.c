#include<stdio.h>
#include<math.h>
void main() 
{
 float a,b,c,d,temp,r1,r2; 
 printf("\nEnter the value of a\t:");
 scanf("%f",&a); 
 printf("Enter the value of b\t:");
 scanf("%f",&b);
 printf("Enter the value of c\t:");
 scanf("%f",&c);

 d=((b*b)-(4*c*a));
 
 if(d==0)
 {
  printf("\nRoots are real and equal\n");
  r1=-b/(2*a);
  printf("\t X1=%f \n \t X2=%f ", r1, r1 );
 }

  else if(d>0)
 {
  printf("\nRoots are real and distinct\n");
  temp=sqrt(d);

  r1=(-b+temp)/(2*a);
  r2=(-b-temp)/(2*a);

  printf("\n\tX1=%f\n\tX2=%f",r1,r2);
 }

  else
 {
  printf("\nRoots are Imaginary\n");
  d*=-1;
  temp=sqrt(d);
  r1=-b/(2*a);
  r2=temp/(2*a);
  printf("\n\tX1=(%f + %fi)\n\tX2=(%f - %fi)",r1,r2,r1,r2);
 }
}