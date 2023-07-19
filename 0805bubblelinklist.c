#include<stdio.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_beg(struct node *);
struct node *temp,*temp1,*temp2,*newnode;
int count_nodes(struct node *);
void display(struct node *);
main()
{

int ch,c;
head=NULL;
   while(1)
   {
     printf("1--insert at begining\n");
     printf("2--display linked list\n");
    printf("3--count linked list\n");


     printf("4--exit\n");

     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
              case 2: display(head);break;
              case 3: c=count_nodes(head);
                   printf("no of nodes=%d\n",c);
                   break;
              case 4: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
   }
   struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}
void display(struct node *head)
{

   if(head==NULL)
   {
     printf("the linkded list is empty\n");
   }
   else
   {
      temp=head;
      while(temp->next!=NULL)
      {
          temp1=temp;
          temp=temp->next;
          if(temp1->data>temp->data)
          {
              temp2=temp1->data;
              temp1->data=temp->data;
              temp->data=temp2;
          }

        printf("%d->",temp->data);
         temp=temp->next;
      }
      }
      printf("\n");
   }

int count_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
       return(count);
    else
    {

        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return(count);
    }
}


