#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	    pid_t cpid;
	int procid=fork();
	if (procid== 0)
		{
		cpid=wait(NULL);printf("Child pid = %d\n", cpid);
		}
	else
		{
		cpid=wait(100);
		printf("Parent pid = %d\n", getpid());
		}
	return 0;
}

