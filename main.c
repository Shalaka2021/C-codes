#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct queue
{
	int data;
	int priority;
	struct queue * next;
};

void enqueue(struct queue ** head,int data,int pri);
int dequeue(struct queue ** head);
int isqueuefull(struct queue *head);
int countnode(struct queue * head);
int isqueueempty(struct queue *head);
void display(struct queue *head);

int main()
{
	struct queue * first=NULL;
	int data,ch,pri;

	while(1)
	{
		printf("\n1-Enqueue\n2-Dequeue\n3-Exit\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			      if(isqueuefull(first))
                        {
                              printf("Queue is full");
                              break;
                        }
				printf("\nEnter the data:");
				scanf("%d",&data);
				printf("\nEnter priority:");
				scanf("%d",&pri);
				enqueue(&first,data,pri);
				display(first);
				break;
			case 2:data=dequeue(&first);
				if(data!=-1)
					printf("\n%d data has been dequeued successfully",data);
				display(first);
				break;
			case 3:exit(1);
			default:printf("Invalid choice");
		}
	}

	return 0;
}

void enqueue(struct queue ** head,int data,int pri)
{
	struct queue * newnode=NULL;
	struct queue * temp=NULL;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	if(newnode==NULL)
	{
		printf("Memory allocation failed");
            return ;
	}
	newnode->data=data;
	newnode->priority=pri;

	if(*head==NULL||pri>=(*head)->priority)
	{
	      newnode->next=*head;
	      *head=newnode;
	      return ;
	}

	temp=*head;
	while(temp->next!=NULL&&pri<temp->next->priority)
            temp=temp->next;

	newnode->next=temp->next;
	temp->next=newnode;
}

int dequeue(struct queue ** head)
{

      struct queue *temp=NULL;
      int data;
      if(isqueueempty(*head))
      {
            printf("Priority queue is empty");
            return -1;
      }

      temp=*head;
      data=(*head)->data;
      *head=(*head)->next;
      temp->next=NULL;
      free(temp);

      return data;
}

int isqueuefull(struct queue *head)
{
      if(countnode(head)==MAX)
            return 1;
      return 0;
}

int countnode(struct queue * head)
{
      int count=0;
      if(head==NULL)
            return 0;
      while(head!=NULL)
      {
            count++;
            head=head->next;
      }

      return count;
}

int isqueueempty(struct queue *head)
{
      if(head==NULL)
            return 1;
      return 0;
}

void display(struct queue *head)
{
      printf("\n");
      while(head)
      {
            printf("|%d||%d|-",head->data,head->priority);
            head=head->next;
      }
}

