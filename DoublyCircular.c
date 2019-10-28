#include<stdio.h>
#include<stdlib.h>

struct node
{
      struct node *prev;
      int data;
      struct node *next;
};

int CountNode(struct node *head,struct node *tail);
void InsertFirst(struct node **head,struct node **tail,int data);
void InsertLast(struct node **head,struct node **tail,int data);
void InsertAtPosition(struct node **head,struct node **tail,int data,int pos);
int DeleteFirst(struct node **head,struct node **tail);
int DeleteLast(struct node **head,struct node **tail);
int DeleteAtPosition(struct node **head,struct node **tail,int pos);
void Display(struct node *head,struct node *tail);
int main()
{
      int data,pos,ch;
      struct node *first=NULL;
      struct node *last=NULL;

      while(1)
      {
            printf("\n1-InsertFirst\n2-InsertLast\n3-InsertAtPosition");
            printf("\n4-DeleteFirst\n5-DeleteLast\n6-DeleteAtPosition");
            printf("\n7Count node\n8-Exit\nEnter your choice:");
            scanf("%d",&ch);

            switch(ch)
            {
                  case 1:
                        printf("\nEnter data:");
                        scanf("%d",&data);
                        InsertFirst(&first,&last,data);
                        Display(first,last);
                        break;
                  case 2:
                        printf("\nEnter data:");
                        scanf("%d",&data);
                        InsertLast(&first,&last,data);
                        Display(first,last);
                        break;
                  case 3:
                        printf("\nEnter data:");
                        scanf("%d",&data);
                        printf("\nEnter position:");
                        scanf("%d",&pos);
                        InsertAtPosition(&first,&last,data,pos);
                        Display(first,last);
                        break;
                  case 4:
                        data=DeleteFirst(&first,&last);
                        if(data!=-1)
                              printf("%d data deleted successfully\n",data);
                        Display(first,last);
                        break;
                  case 5:
                        data=DeleteLast(&first,&last);
                        if(data!=-1)
                              printf("%d data deleted successfully\n",data);
                        Display(first,last);
                        break;
                  case 6:
                        printf("\nEnter position of data to be deleted:");
                        scanf("%d",&pos);
                        data=DeleteAtPosition(&first,&last,pos);
                        if(data!=-1)
                              printf("%d data deleted successfully\n",data);
                        Display(first,last);
                        break;
                  case 7:
                        data=CountNode(first,last);
                        printf("Total nodes :%d",data);
                        Display(first,last);
                        break;
                  case 8:exit(1);
                  default:printf("\nInvalid choice");
            }
      }
      return 0;
}

int CountNode(struct node *head,struct node *tail)
{
      int count=0;
      if(head==NULL)
            return 0;
      do
      {
            count++;
            head=head->next;
      }while(head!=tail->next);

      return count;
}

void InsertFirst(struct node **head,struct node **tail,int data)
{
      struct node *newnode=NULL;

      newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
      {
            printf("\nMemory allocation failed");
            return ;
      }

      newnode->data=data;

      if(*head==NULL)
      {
            *head=newnode;
            *tail=newnode;
            newnode->prev=newnode;
            newnode->next=newnode;
            return ;
      }

      newnode->prev=*tail;
      newnode->next=*head;
      (*head)->prev=newnode;
      (*tail)->next=newnode;
      *head=newnode;
}

void InsertLast(struct node **head,struct node **tail,int data)
{
      struct node *newnode=NULL;

      newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
      {
            printf("\nMemory allocation failed");
            return ;
      }

      newnode->data=data;

      if(*head==NULL)
      {
            *head=newnode;
            *tail=newnode;
            newnode->prev=newnode;
            newnode->next=newnode;
            return ;
      }

      newnode->prev=*tail;
      newnode->next=*head;
      (*head)->prev=newnode;
      (*tail)->next=newnode;
      *tail=newnode;
}

void InsertAtPosition(struct node **head,struct node **tail,int data,int pos)
{
      struct node *newnode=NULL;
      struct node *temp=NULL;
      int count;

      count=CountNode(*head,*tail);

      if(pos<=0||pos>count+1)
      {
            printf("\nPosition is Invalid\n");
            return ;
      }

      if(pos==1)
      {
            InsertFirst(head,tail,data);
            return ;
      }

      if(pos==count+1)
      {
            InsertLast(head,tail,data);
            return ;
      }

      newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
      {
            printf("\nMemory allocation failed");
            return ;
      }
      newnode->data=data;
      temp=*head;
      count=1;
      while(count<pos-1)
      {
            count++;
            temp=temp->next;
      }
      newnode->prev=temp;
      newnode->next=temp->next;
      temp->next=newnode;
      newnode->next->prev=newnode;
}

int DeleteLast(struct node **head,struct node **tail)
{
      int data;

      if(*head==NULL)
            return -1;

      if(*head==*tail)
      {
            data=(*head)->data;
            (*head)->prev=NULL;
            (*head)->next=NULL;
            free(*head);
            *head=*tail=NULL;
            return data;
      }

      data=(*tail)->data;
      (*tail)->prev->next=*head;
      (*head)->prev=(*tail)->prev;
      (*tail)->next=NULL;
      (*tail)->prev=NULL;
      free(*tail);
      *tail=(*head)->prev;

      return data;
}

int DeleteFirst(struct node **head,struct node **tail)
{
      int data;

      if(*head==NULL)
            return -1;

      if(*head==*tail)
      {
            data=(*head)->data;
            (*head)->prev=NULL;
            (*head)->next=NULL;
            free(*head);
            *head=*tail=NULL;
            return data;
      }

      data=(*head)->data;
      (*tail)->next=(*head)->next;
      (*head)->next->prev=*tail;
      (*head)->next=NULL;
      (*head)->prev=NULL;
      free(*head);
      *head=(*tail)->next;

      return data;
}

int DeleteAtPosition(struct node **head,struct node **tail,int pos)
{
      int count,data;
      struct node *temp=NULL;

      if(*head==NULL)
            return -1;

      count=CountNode(*head,*tail);

      if(pos<=0||pos>count)
      {
            printf("\nPosition is invalid");
            return -1;
      }

      if(pos==1)
      {
            return DeleteFirst(head,tail);
      }

      if(pos==count)
      {
            return DeleteLast(head,tail);
      }

      temp=*head;
      count=1;
      while(count<pos)
      {
            count++;
            temp=temp->next;
      }

      data=temp->data;
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      temp->prev=NULL;
      temp->next=NULL;
      free(temp);

      return data;
}

void Display(struct node *head,struct node *tail)
{
      if(head==NULL)
            return ;
      printf("\n");
      do
      {
            printf("|%d|->",head->data);
            head=head->next;
      }while(head!=tail->next);
      printf("\n");
}
