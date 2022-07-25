#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
	key_t key = ftok("file",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	printf("Key : %d",shmid);
	void *shmdmry = shmat(shmid,NULL,0);
	printf("\nProcess attached at %p",shmdmry);
	char *str = (char*) shmdmry;
	printf("\nEnter the data to write : ");
	fgets(str,100,stdin);
	printf("\nData Written into memory!!!\n");
	shmdt(str);
}
