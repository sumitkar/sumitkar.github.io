#include<stdio.h>
void main()
{
	int n,i,j,flag; 
	printf("\n\nEnter the limit\t:"); 
	scanf("%d",&n);
	printf("\nThe prime numbers within the given limit:\n");
	for(i=1;i<=n;i++)
		{ 
		flag=0;
		for(j=2;j<=i/2;j++)
			{ 
			if(i%j==0) 
				{ 
				flag=1;
				break;
				}
			}
		if(flag==0)
			printf("%d\t",i);
		}
}