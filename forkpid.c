#include<stdio.h>
#include<unistd.h>
int main()
{
	int i,n;
	int sumc=0,sump=0;
	printf("Enter a number : ");
	scanf("%d",&n);
	int pid = fork();
	if(pid == 0)
	{
		printf("\n\nChild Process : \n");
		printf("Process ID : %d \n",getpid());
		printf("PPID : %d\nSum of Even Numbers are : ",getppid());
		for(i=0;i<=n;i+=2)
			sumc+=i;
		printf("%d ",sumc);
		printf("\n");
	}
	else if(pid > 1)
	{
		printf("\nParent Process : ");
		printf("\nProcess ID : %d\nSum of Odd Numbers are : ",getpid());
		for(i=1;i<=n;i+=2)
			sump+=i;	
		printf("%d ",sump);
	}
	return 0;
}
