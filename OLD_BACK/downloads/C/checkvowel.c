#include <stdio.h>

void main()
 {
  char in;
  printf("Enter Character: ");
  scanf("%c", &in);
  if(in>=65&&in<=90 || in>=97&& in<=122)
  {
   if(in<97)
 	 in=in+32;
   if(in=='a'||in=='e'||in=='i'||in=='o'||in=='u')
 	 printf("vowel");
   else
         printf("consonent");
  }
  else
   printf("Not an valid Alphabet");
 }