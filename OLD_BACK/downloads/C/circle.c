#include<stdio.h>
#define PI 3.142 

void main() 
{
 float r,a,c;
 printf("\nEnter the radius of circle:\t");
 scanf("%f",&r);
 a=PI*r*r; 
 printf("\nThe area of the circle:\t%f",a);
 c=2*PI*r; 
 printf("\nThe circumference of the circle: %f",c);
}