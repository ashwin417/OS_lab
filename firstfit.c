#include<stdio.h>
void firstfit(int [],int [], int,int);
void print(int [], int[], int);
int main()
{
	int np,nm,i;
	printf("Enter the number of memory partitions : ");
	scanf("%d",&nm);
	printf("Enter the number of process : ");
	scanf("%d",&np);
	
	int mempar[nm], prcsize[np];
	
//Input the memory partitions
	printf("Enter the memory partitions in KB : ");
	for(i=0;i<nm;i++)
		scanf("%d",&mempar[i]);
//Input the process
	printf("Enter the process size : ");
	for(i=0;i<np;i++)
		scanf("%d",&prcsize[i]);
	firstfit(mempar,prcsize,nm,np);

}

void firstfit(int mempar[], int prcsize[], int nm, int np)
{
	int i,j;
	int temp[nm];
	for(i=0;i<nm;i++)
		temp[i]=mempar[i];
	int allocate[np];
	for(i=0;i<np;i++)
		allocate[i]=-1;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nm;j++)
		{
			if(mempar[j]>=prcsize[i])
			{
				allocate[i]=j;
				mempar[j] -= prcsize[i];
				break;
			}
		}
	}
	print(prcsize,allocate,np);
}

void print(int p[], int allocate[], int n)
{

	printf("\nFirst Fit\nPNo\tPrc size\tBlockno\n");
	for(int i=0; i<n; i++)
	{
	printf(" %d\t%d\t\t",i+1,p[i]);
	if(allocate[i]!=-1)
		printf("%d\n",allocate[i]+1);
	else
		printf("Not Allocated\n");
	
	}
}
