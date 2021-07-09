#include<stdio.h>
void main()
{
 float p;
 float ir,t;
 float in;

  printf("Principle amount : ");
  scanf("%f",&p);
  printf("\nInterest : ");
  scanf("%f",&ir);
  printf("\nTime (in year) : ");
  scanf("%f",&t);
  in=p*ir*t/100;
  printf("\nYou will get interest : Rs. %.2f",in);

}
