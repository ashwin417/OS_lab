#include<stdio.h>
void worstfit(int [],int [],int,int);
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
	worstfit(mempar,prcsize,nm,np);

}

void worstfit(int mempar[], int prcsize[], int nm, int np)
{
	int i,j;
	int allocate[np];
	for(i=0;i<np;i++)
		allocate[i]=-1;
	for(i=0;i<np;i++)
	{
		int worst = -1;
		for(j=0;j<nm;j++)
		{
			if(mempar[j]>=prcsize[i])
			{
				if(worst == -1)
					worst =j;
				else if(mempar[worst]<mempar[j])
					worst =j;
			}
		}
		
		if(worst !=-1)
			{
			allocate[i]=worst;
			mempar[worst] -= prcsize[i];
			}
	}
	print(prcsize,allocate,np);
}

void print(int p[],int allocate[], int n)
{

	printf("\nWorst Fit\nPNo\tPrc size\tBlockno\n");
	for(int i=0; i<n; i++)
	{
	printf(" %d\t%d\t\t",i+1,p[i]);
	if(allocate[i]!=-1)
		printf("%d\n",allocate[i]+1);
	else
		printf("Not Allocated\n");
	
	}
}
