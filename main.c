#include<stdio.h>
#include<stdlib.h>

struct node
{
      struct node *prev;
      int data;
      struct node *next;
};

void InsertFirst(struct node **,int );
void InsertLast(struct node **,int );
void Display(struct node *);
int CountNode(struct node *);
int SearchAllOccurances(struct node *,int );
int SearchFirstOccurance(struct node *,int );
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int main()
{
      int ch,key,data,count,totoccur,pos;
      struct node *first=NULL;
      while(1)
      {
            printf("\n1-Insertfirst\n2-Insertlast\n3-Display\n4-Count nodes\n5-Search all occurances");
            printf("\n6-Search first occurances\n7-Delete first\n8-Delete last\n9-Insert at position");
            printf("\n10-Delete at position\n9-Exit\nEnter your choice:");
            scanf("%d",&ch);
            switch(ch)
            {
                  case 1:
                        printf("\nEnter node data:");
                        scanf("%d",&data);
                        InsertFirst(&first,data);
                        break;
                  case 2:
                        printf("\nEnter node data:");
                        scanf("%d",&data);
                        InsertLast(&first,data);
                        break;
                  case 3:Display(first);
                        break;
                  case 4:
                        count=CountNode(first);
                        printf("\nTotal nodes are:%d",count);
                        break;
                  case 5:
                        printf("\nEnter key to search:");
                        scanf("%d",&key);
                        totoccur=SearchAllOccurances(first,key);
                        printf("\nTotal occurances are:%d",totoccur);
                        break;
                  case 6:
                        printf("\nEnter key to search:");
                        scanf("%d",&key);
                        pos=SearchFirstOccurance(first,key);
                        printf("\nFirst position at which key is found is:%d",pos);
                        break;
                  case 7:
                        data=DeleteFirst(&first);
                        if(data!=-1)
                              printf("%d deleted successfully",data);
                        break;
                  case 8:
                        data=DeleteLast(&first);
                        if(data!=-1)
                              printf("%d deleted successfully",data);
                        break;
                  case 9:exit(1);
                  default:printf("\nInvalid choice");
            }
      }

      return 0;
}

void InsertFirst(struct node **head,int no)
{
      struct node *newnode=NULL;
      newnode=(struct node *)malloc(sizeof(struct node));

      if(newnode==NULL)
      {
            printf("\nMemory allocation failed");
            return ;
      }
      newnode->data=no;
      newnode->prev=NULL;

      if(*head==NULL)
      {
            newnode->next=NULL;
            *head=newnode;
            return ;
      }
      (*head)->prev=newnode;
      newnode->next=*head;
      *head=newnode;
}

void InsertLast(struct node **head,int no)
{
      struct node *newnode=NULL;
      struct node *temp=NULL;
      newnode=(struct node *)malloc(sizeof(struct node));

      if(newnode==NULL)
      {
            printf("\nMemory allocation failed");
            return ;
      }
      newnode->data=no;
      newnode->next=NULL;

      if(*head==NULL)
      {
            newnode->prev=NULL;
            *head=newnode;
            return ;
      }

      temp=*head;
      while(temp->next!=NULL)
            temp=temp->next;

      newnode->prev=temp;
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
            printf("|%d|->",head->data);
            head=head->next;
      }
}

int CountNode(struct node *head)
{
      int count=0;

      while(head!=NULL)
      {
            count++;
            head=head->next;
      }
      return count;
}

int SearchAllOccurances(struct node *head,int key)
{
      int count=0;

      while(head!=NULL)
      {
            if(head->data==key)
                  count++;
            head=head->next;
      }

      return count;
}

int SearchFirstOccurance(struct node *head,int key)
{
      int pos=0;
      while(head!=NULL)
      {
            pos++;
            if(head->data==key)
                  break;
            head=head->next;
      }
      if(head==NULL)
            pos=0;
      return pos;
}

int DeleteFirst(struct node **head)
{
      int data;
      struct node * temp=NULL;
      if(*head==NULL)
            return -1;

      /*if((*head)->next==NULL)
      {
            data=(*head)->data;
            *head=NULL;
            return data;
      }

      data=(*head)->data;
      *head=(*head)->next;
      (*head)->prev->next=NULL;
      free((*head)->prev);
      (*head)->prev=NULL;
      return data;*/
      temp=*head;
      *head=temp->next;
      data=temp->data;
      temp->next=NULL;
      if(*head!=NULL)
            (*head)->prev=NULL;
      free(temp);
      return data;
}

int DeleteLast(struct node **head)
{
      struct node * temp=NULL;
      int data;

      if(*head==NULL)
            return -1;
      /*
      if((*head)->next==NULL)
      {
            data=(*head)->data;
            *head=NULL;
            return data;
      }
      temp=*head;
      while(temp->next->next!=NULL)
            temp=temp->next;

      data=temp->next->data;
      temp->next->prev=NULL;
      free(temp->next);
      temp->next=NULL;
      */
      temp=*head;
      while(temp->next!=NULL)
            temp=temp->next;

      data=temp->data;
      if(temp->prev==NULL)
            *head=NULL;
      else
      {
            temp->prev->next=NULL;
            temp->prev=NULL;
      }
      free(temp);

      return data;
}
