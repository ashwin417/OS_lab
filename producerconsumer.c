#include<stdio.h>
int counter = 0,in = 0, out = 0, Buffer_size = 10;
int buffer[10];
void producer()
{
	int next_produced=0;
	//while( counter == Buffer_size);
	buffer[in] = ++next_produced;
	in = (in + 1) % Buffer_size;
	counter++;
	
}

void consumer()
{
	int next_consumed;
	//while( counter == 0 );
	next_consumed = buffer[out];
	out = (out + 1) % Buffer_size;
	counter--;
}

int main()
{
int ch,k=0;
while(ch!=3)
	{
	printf("\n1. Producer 2. Consumer 3. Exit \nEnter option: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : if(counter == Buffer_size)
				{
				printf("\nBuffer Full\n");
				}
				else
				{ 
				 printf("\nProducer produces the item %d\n",++k);
				 producer();
				} 
				break;
		case 2 :{
			if(counter == 0)
				{
				printf("\nBuffer empty\n");}
			else{ 
				printf("\nConsumer Consumed the item %d\n",k--); consumer();
				}
			}
			break;
		default : printf("Bad Input\n"); 
	}
	}
}
