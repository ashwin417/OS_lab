#include<stdio.h>
void worstfit(int [],int [],int,int);
void firstfit(int [],int [],int,int);
void bestfit(int [],int [],int,int);
void print(int [], int[], int);
int main()
{
	int np,nm,i;
	printf("Enter the number of memory partitions : ");
	scanf("%d",&nm);
	printf("Enter the number of process : ");
	scanf("%d",&np);
	
	int mempar[nm], prcsize[np],memparb[nm],memparw[nm];
	
//Input the memory partitions
	printf("Enter the memory partitions in KB : ");
	for(i=0;i<nm;i++)
		scanf("%d",&mempar[i]);
		memparb[i]=mempar[i];
		memparw[i]=mempar[i];
//Input the process
	printf("Enter the process size : ");
	for(i=0;i<np;i++)
		scanf("%d",&prcsize[i]);
		
	int ch;
	do{
	printf("\n1. First Fit\t2. Best Fit\t3. Worst Fit\t4. Exit\nEnter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : printf("\n-------First Fit-------"); firstfit(mempar,prcsize,nm,np);break;
		case 2 : printf("\n-------Best Fit-------"); bestfit(memparb,prcsize,nm,np);break;
		case 3 : printf("\n-------Worst Fit-------");worstfit(memparw,prcsize,nm,np);break;
		default : printf("\nWrong Option!!!");break;
	}
	}while(ch!=4);
}

void firstfit(int mempar[], int prcsize[], int nm, int np)
{
	int i,j;
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

void bestfit(int mempar[], int prcsize[], int nm, int np)
{
	int i,j;
	int allocate[np];
	for(i=0;i<np;i++)
		allocate[i]=-1;
	for(i=0;i<np;i++)
	{
		int best = -1;
		for(j=0;j<nm;j++)
		{
			if(mempar[j]>=prcsize[i])
			{
				if(best == -1)
					best =j;
				else if(mempar[best]>mempar[j])
					best =j;
			}
		}
		
		if(best !=-1)
			{
			allocate[i]=best;
			mempar[best] -= prcsize[i];
			}
	}
	print(prcsize,allocate,np);
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

	printf("\n\nPNo\tPrc size\tBlockno\n");
	for(int i=0; i<n; i++)
	{
	printf(" %d\t%d\t\t",i+1,p[i]);
	if(allocate[i]!=-1)
		printf("%d\n",allocate[i]+1);
	else
		printf("Not Allocated\n");
	
	}
}
