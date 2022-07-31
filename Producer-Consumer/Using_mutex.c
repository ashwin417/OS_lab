#include<stdio.h>

int mutex = 1;
int full = 0, empty = 10, x=0;

void producer()
{
--mutex;
++full;
--empty;
x++;
printf("Producer produces the item %d",x);
++mutex;
}

void consumer()
{
--mutex;
--full;
++empty;
printf("Consumer consumed the item %d",x--);
++mutex;
}

int main()
{
int ch;
do
{
	printf("\n1.Producer\t2.Consumer\t3.Exit\nEnter the Option : ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 : 	if((mutex==1)&&(full!=10)){producer();}
			else printf("Buffer is Full!!!");
			break;
	case 2 :	if((mutex==1)&&(empty!=10)){consumer();}
			else printf("Buffer is empty!!!");
			break;
	default : printf("Wrong Option");
	
	}
}while(ch!=3);
return 0;

}
