#include<stdio.h>
int main()
{
	int i,burst=0, n,TQ;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n],y=n;
	int Wt[n],rmt[n],t=0,flag=0,Ta[n],j=0;
	printf("Enter the process number, Arrival time & burst time: \nPNo\tAT\tBT\n");
	for(i=0;i<n;i++)
		{
		scanf("%d%d%d",&prc[i],&At[i],&Bt[i]);
		rmt[i]=Bt[i];
		}
	printf("\nEnter the Time Quantum for Scheduling in milliseconds : ");
	scanf("%d",&TQ);

// Sorting according to process number
	int temp,pos;
/*	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(prc[j]<prc[pos])
				pos = j;
		}
//Swapping 
	temp=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=temp;
	
	temp=At[i];
	At[i]=At[pos];
	At[pos]=temp;
	
	temp=prc[i];
	prc[i]=prc[pos];
	prc[pos]=temp;
	}	
	*/
	
// Waiting time & turn around time calculation
	
	j=0;
		for(i=0,t=0;y!=0;)
		{	
			
			
				if(rmt[i]<=TQ && rmt[i]>0)
					{
					t+=rmt[i]; 
					rmt[i]=0;
					flag = 1;
					}
				else if(rmt[i]>0) 
					{
					rmt[i]-=TQ;
					t+=TQ;
					}
				if(flag==1 && rmt[i]==0)
				{
				y--;
				prc[j] = i+1;
				Wt[j] = t-At[i]-Bt[i];
				Ta[j++] = t-At[i];
				  
				flag = 0;
				}
				if(i==n-1)
		   		  	i=0;
		   		else if(At[i+1]<=t)
		    			 i++;
		  		else
		   		  	 i=0;
				}
		

//Sorting according to process number


	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(prc[j]<prc[pos])
				pos = j;
		}
//Swapping 
	temp=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=temp;
	
	temp=At[i];
	At[i]=At[pos];
	At[pos]=temp;
	
	temp=prc[i];
	prc[i]=prc[pos];
	prc[pos]=temp;
	
	temp=Wt[i];
	Wt[i]=Wt[pos];
	Wt[pos]=temp;
	
	temp=Ta[i];
	Ta[i]=Ta[pos];
	Ta[pos]=temp;
	
	}	
	
//Displaying the table with Waiting time and turn around time
	printf("\nPno\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\n",prc[i],Wt[i],Ta[i]);
	}
	
//Finding Average waiting time	
	int SumWT=0;
	for(i=0;i<n;i++)
	{
		SumWT+=Wt[i];
	}
	float AvgWT=(float)SumWT/(float)n;
	
//Finding Average Turn Around time
	int SumTA=0;
	for(i=0;i<n;i++)
	{
		SumTA+=Ta[i];
	}
	float AvgTa=(float)SumTA/(float)n;
	
	printf("\nAverage Waiting Time = %f milliseconds\nAverage Turnaround time = %f milliseconds\n",AvgWT,AvgTa);
	
	return 0;
}



