#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int rear=-1;
int front=0;
int queue[MAX];

void enqueue(int data);
int isqueuefull();
int dequeue();
int isqueueempty();
void display();

int main()
{
	int ch,data;

	while(1)
	{
		printf("\n1-Enqueue\n2-Dequeue\n3-Exit\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: if(isqueuefull())
				{
					printf("\nQueue is full");
					break;
				}
				printf("\nEnter the data:");
				scanf("%d",&data);
				enqueue(data);
				display();
				break;
			case 2:data=dequeue();
				if(data!=-1)
					printf("\n%d data has been dequeued succesfully",data);
				display();
				break;
			case 3:exit(1);
			default:printf("Invalid choice");
		}
	}

	return 0;
}

void enqueue(int data)
{
     /*	if(isqueuefull())
	{
		printf("\nQueue is full");
		return ;
        }
     */
	if(rear==MAX-1&&front>0)
		rear=0;
	else
		rear++;

	queue[rear]=data;
}

int isqueuefull()
{
	if((front==0&&rear==MAX-1)||(rear==front-1&&rear!=-1))
		return 1;
	return 0;
}

int dequeue()
{
	int data;
	if(isqueueempty())
	{
		printf("\nQueue is empty");
		return -1;
	}

	data=queue[front];

	if(front==rear)
	{
		front=0;
		rear=-1;  //Reset the front and rear
	}
	else if(front==MAX-1/*&&rear!=-1*/)
		front=0;
	else
		front++;

	return data;
}

int isqueueempty()
{
	if(rear==-1)
		return 1;
	return 0;
}

void display()
{
	int i;
	if(isqueueempty())
		return ;
	printf("\n");

	for(i=front;i<=MAX-1;i++)
	{
		printf("|%d|",queue[i]);
		if(i==rear)
			break;
	}
	if(rear<front)
	{
		for(i=0;i<=rear;i++)
			printf("|%d|",queue[i]);
	}
}



