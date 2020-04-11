#include<stdio.h>
void main() {
   int arr[10], i, j, k, size;
   printf("\nEnter array size : ");
	scanf("%d", &size);

   printf("\nAccept Numbers : \n");
   for (i = 0; i < size; i++)
	{
	printf("Data [%d]: ",i+1);
	scanf("%d", &arr[i]);
	}

   printf("\nThe Array is : ");
   for (i = 0; i < size; i++)
	printf("%d ", arr[i]);

    getch();
}
