#include<stdio.h>
int counter = 0,in = 0, out = 0, Buffer_size = 10;
int buffer[10];
void producer()
{
	printf("\nEnter item");
	int next_produced;
	scanf("%d",&next_produced);
	while( counter == Buffer_size);
	buffer[in] == next_produced;
	in = (in + 1) % Buffer_size;
	counter++;
	
}

void consumer()
{
	int next_consumed;
	while( counter == 0 );
	next_consumed = buffer[out];
	out = (out + 1) % Buffer_size;
	counter--;
}

int main()
{
int ch;

while(1)
	{
	printf("\n1. Producer\n2. Consumer\n Enter option:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : if(counter == Buffer_size)
				{
				printf("Buffer Full\n");
				}
				else
				{ 
				 printf("Producer\n");producer();
				 } 
				 break;
		case 2 : {
			if(counter == 0)
			{printf("Buffer empty\n");}
			else{ printf("Consumer\n"); consumer();
			}}break;
		default : printf("Bad Input\n"); 
	}
	}
}
