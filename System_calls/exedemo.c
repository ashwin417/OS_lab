#include<stdio.h>
#include<unistd.h>
int main()
{
char *arg1 = "/home/s4c2/Documents/s4c2/EXEC";
char *args = "-all";
execlp("ls","ls",args,arg1,NULL);
printf("End....");
return 0;
}
