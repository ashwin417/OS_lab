#include<stdio.h>
#include<stdlib.h>

void fifo(int [],int,int);
void main()
{
	int n,i,intialhead,ch;
	printf("Enter the number of requests : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter the sequence : ");
	for(i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("Enter the intial head : ");
	scanf("%d",&intialhead);
	fifo(req,intialhead,n);
}

void fifo(int p[], int intial, int n)
{
	int i,total=0;
	for(i=0;i<n;i++)
	{
		total+=abs(p[i]-intial);
		intial = p[i];
	}
	printf("\nTotal head movement = %d",total);
}
