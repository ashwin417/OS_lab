//Incomplete!!!!!!!

#include<stdio.h>
void main()
{
	int ninst,np,i,j;
	printf("Enter the number of process : ");
	scanf("%d",&np);
	printf("Enter the number of resource instances : ");
	scanf("%d",&ninst);

//Inputting Allocation & Max Matrix	
	int allocmat[np][ninst], max[np][ninst];
	printf("Input the Allocation Matrix : \n");
	for(i=0;i<np;i++)
	{
		for(j=0;j<ninst;i++)
			{
				scanf("%d",&allocmat[i][j]);
			}
	}

	printf("Input the Max Matrix : \n");	
	for(i=0;i<np;i++)
	{
		for(j=0;j<ninst;i++)
			{
				scanf("%d",&max[i][j]);
			}
	}

//Calculate need matrix
	int need[np][ninst];
	for(i=0;i<np;i++)
	{
		for(j=0;j<ninst;i++)
			{
			need[i][j] = max[i][j] - allocmat[i][j];
			}
	}
	
	
}
