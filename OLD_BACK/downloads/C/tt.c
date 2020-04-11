#include<stdio.h>

int OR(int,int);
int AND(int,int);
int XOR(int,int);
int NOT(int);

void main()
{
 int a,b,ch,o;

 printf("\n-:MENU:-\n1.AND\n2.OR\n3.NOT\n4.XOR\n0.Exit\n");
 do{
    printf("\nEnter Choice:");
    scanf("%d",&ch);

    switch(ch)
     {
      case 1:
             printf ("\nTruth Table for AND\nA B  \tO");
             for(a=0;a<=1;a++)
             {
              for(b=0;b<=1;b++)
                { 
                  o=AND(a,b);
                  printf("\n%d %d \t%d",a,b,o);
                }
             }
              break;
      case 2:
             printf ("\nTruth Table for OR\nA B  \tO");
             for(a=0;a<=1;a++)
             {
              for(b=0;b<=1;b++)
                {
                o=OR(a,b);
                printf("\n%d %d \t%d",a,b,o);
                }
             }
              break;
      case 3: 
             printf ("\nTruth Table for NOT\nA  \tO");
             for(a=0;a<=1;a++)
             {
             o=NOT(a);
             printf("\n%d  \t%d",a,o);
             }
              break;
      case 4:
             printf ("\nTruth Table for XOR\nA B  \tO");
             for(a=0;a<=1;a++)
             {
              for(b=0;b<=1;b++)
                {
                o=XOR(a,b);
                printf("\n%d %d \t%d",a,b,o);
                }
             }
              break;

      case 0: exit();
              break;
             default: printf("\nError");
             }
      }while(ch!=0);

}


int OR(int a, int b)
{
if(a==0&&b==0)
   return 0;
else
   return 1;
}

int AND(int a, int b)
{
if (a==1&&b==1)
   return 1;
else
   return 0;
}

int NOT(int a)
{
if (a==0)
   return 1;
else
   return 0;
}

int XOR(int a,int b)
{
if (a==0&&b==1||a==1&&b==0)
   return 1;
else
   return 0;
}