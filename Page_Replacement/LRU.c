#include<stdio.h>
void LRU(int prs[], int n, int frame);
int findLRU(int time[], int n);
void print(int [],int);

void main()
{
	int n,i,frame;
	printf("Enter the Length of sequence : ");
	scanf("%d",&n);
	int prs[n];
	printf("Enter the Sequence : ");
	for(i=0;i<n;i++)
		scanf("%d",&prs[i]);
	printf("Enter the number of frame : ");
	scanf("%d",&frame);
	LRU(prs,n,frame); 
}

void LRU(int pg[], int n, int f)
{

	int frames[f], counter = 0, time[10], flag1, flag2, i, j, pos, pagefault = 0;
	printf("\nValues\t");
	for(i=1;i<=f;i++)
		printf("Frame%d\t",i);
	printf("\n");
	for(i = 0; i < f; i++)
	{
		frames[i] = -1;
	}
	
	for(i = 0; i < n; i++)
	{
		flag1 = flag2 = 0;
		printf("%d =>\t",pg[i]);
		for(j = 0; j < f; j++)
		{
			if(frames[j] == pg[i])
			{
				counter++;
				time[j] = counter;
				flag1 = flag2 = 1;
				printf("\tHit!!!\n");
				break;
			}
		}
		
		if(flag1 == 0)
		{
			for(j = 0; j < f; j++ )
			{
				if(frames[j] == -1)
				{
					counter++;
					pagefault++;
					frames[j] = pg[i];
					time[j] = counter;
					flag2 = 1;
					print(frames,f);
					break;
				}
			}    
		}
		
		if(flag2 == 0)
		{
			pos = findLRU(time, f);
			counter++;
			pagefault++;
			frames[pos] = pg[i];
			time[pos] = counter;
			print(frames,f);
			
		}
		
		
	}
	
	printf("\n\nTotal Page Fault = %d\n", pagefault);
}

int findLRU(int time[], int n)
{
	int i, minimum = time[0], pos = 0;
	
	for(i = 1; i < n; i++)
	{
		if(time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
		}
	}
	
	return pos;
}

void print(int frames[], int f)
{
	int j;
	for(j=0;j<f;j++)
	{	
		if(frames[j]!=-1)
			printf("%d\t",frames[j]);
		else
			printf("\t");
	}
	printf("\n");
}
