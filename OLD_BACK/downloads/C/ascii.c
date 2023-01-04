#include<stdio.h>
void main()
{
 char chl='a';
 char chu='A';
 int i;
 printf("\n===========================");
 for(i=1;i<=26;i++,chu++,chl++)
    printf("\n|%c |  %d \t|| %c| %d  |",chl,chl, chu, chu);  	
 printf("\n===========================");
}


