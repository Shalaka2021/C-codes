#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *next;
};
void Insertfirst(struct node **,int );
void Insertlast(struct node **,int );
void Display(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int main()
{
      int data,ch, deleteddata;
      struct node *first=NULL;
      while(1)
      {
            printf("\n1-Insert at first\n2-Insert at last\n3-Display\n4-Delete first node");
            printf("\n5-Delete last node\n6-Exit\nEnter your choice:");
            scanf("%d",&ch);
            switch(ch)
            {
                  case 1:printf("\nEnter data:");
                        scanf("%d",&data);
                        Insertfirst(&first,data);
                        break;
                  case 2:printf("\nEnter data:");
                        scanf("%d",&data);
                        Insertlast(&first,data);
                        break;
                  case 3:Display(first);
                        break;
                  case 4:
                        deleteddata=DeleteFirst(&first);
                        printf("|%d| data deleted successfully",deleteddata);
                        break;
                  case 5:
                        deleteddata=DeleteLast(&first);
                        printf("|%d| data deleted successfully",deleteddata);
                        break;
                  case 6:exit(1);
                  default:printf("\nInvalid choice");
            }
      }

      return 0;
}

void Insertfirst(struct node **head,int no)
{
      struct node *temp=NULL;
      temp=(struct node *)malloc(sizeof(struct node));

      if(temp==NULL)
      {
            printf("Memory allocation failed");
            return ;
      }
      temp->data=no;
      temp->next=*head;
      *head=temp;
}
void Insertlast(struct node **head,int data)
{
      struct node *newnode=NULL;
      struct node *temp=NULL;
      newnode=(struct node *)malloc(sizeof(struct node));

      if(newnode==NULL)
      {
            printf("Memory allocation failed");
            return ;
      }
      newnode->data=data;
      newnode->next=NULL;
      if(*head==NULL)
      {
            *head=newnode;
            return ;
      }
      temp=*head;
      while(temp->next!=NULL)
            temp=temp->next;
      temp->next=newnode;
}

void Display(struct node *head)
{
      if(head==NULL)
      {
            printf("\nLinked list is empty");
            return ;
      }
      while(head!=NULL)
      {
            printf("|%d|",head->data);
            head=head->next;
      }
}

int DeleteFirst(struct node **head)
{
      struct node *temp=NULL;
      int no;
      if(*head==NULL)
            return -1;
      temp=*head;
      *head=temp->next;
      temp->next=NULL;

      no=temp->data;
      free(temp);
      return no;
}

int DeleteLast(struct node **head)
{
      struct node *temp=NULL;
      int data;
      temp=*head;

      if((*head)->next==NULL)
      {
            data=(*head)->data;
            free(*head);
            *head=NULL;
            return data;
      }
      while(temp->next->next!=NULL)
            temp=temp->next;

      data=temp->next->data;
      free(temp->next);
      temp->next=NULL;

      return data;

}
