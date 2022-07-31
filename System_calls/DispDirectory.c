#include<stdio.h>
#include<dirent.h>
int main()
{
	struct dirent *de;
	printf("Enter the directory name along with its path to list it's contents : ");
	char dirpath[50];
	scanf("%s",dirpath);
	DIR *dr = opendir(dirpath);
	if(dr == NULL)
		{
			printf("\n\tCouldnot open current directory !!!");
			return 0;
		}
	printf("\nDirectories in %s are : \n",dirpath);
	while((de = readdir(dr))!= NULL)
  {
		printf("\t%s\n\n",de->d_name);
  }
	closedir(dr);
	return 0;
}
