#include<stdio.h>
#define pi 3.14

void main()
{
    int r;
    float p;
    printf("Enter the value of radius: ");
    scanf("%d", &r); //user input
    p=2*pi*r;
    printf("Perimeter=%f",p);
}