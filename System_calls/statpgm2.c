#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>



int main()
{
struct stat sfile;
ssize_t read;
char* buffer = 0;
size_t buf_size = 0;

printf("Enter the name of a file to check: \n");
read = getline(&buffer, &buf_size, stdin);
 printf("Last status change:       %s", ctime(&sfile.st_ctime));

return 0;
}


