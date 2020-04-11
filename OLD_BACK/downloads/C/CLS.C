#include<stdio.h>

void clearmyscreen();

void main()
 {
  printf("hello");
  getch();
  clearmyscreen();
  getch();
 }

void clearmyscreen()
 {
  system("cls");
 }