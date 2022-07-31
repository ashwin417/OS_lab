#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

void statfile(struct stat sfile);

int main()
{
char path[100];
struct stat sfile;
printf("Enter the name of a file to check: \n");
scanf("%s",path);
stat(path, &sfile	);
statfile(sfile);

return 0;
}

void statfile(struct stat sfile)
{
printf("\nFile st_uid %d \n",sfile.st_uid);
printf("\nFile st_size %ld Bytes \n",sfile.st_size);

}
