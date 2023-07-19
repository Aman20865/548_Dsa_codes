#include<stdio.h>
#include<stdlib.h>
struct node
{
  char data[20];
  struct node *next;
};
struct node*insert(struct node*newnode);
struct node*modify_delete(struct node*head,int pos);
struct node*modify_add(struct node*newnode,int pos);
void display(struct node*head);
struct node*head,*temp,*temp1,*newnode;

main()
{
  head=NULL;
  int ch,c,pos,d;
  while(1)
  {
  printf("1--insert songs\n");
        printf("2--delete the song\n");
        printf("3--add the song\n");
        printf("4--display list\n");
        printf("5--exit\n");

  printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
  case 1: newnode=(struct node *)malloc(sizeof(struct node));
                 printf("enter the data\n");
                 scanf("%s",&newnode->data);
                 head=insert(newnode);
                 break;
  case 2: printf("enter the position\n");
            scanf("%d",&pos);

            head=modify_delete(head,pos);
                 break;
                 case 3:printf("enter the position\n");
            scanf("%d",&pos);
             newnode=(struct node *)malloc(sizeof(struct node));
                 printf("enter the data\n");
                 scanf("%s",&newnode->data);
                 head=modify_add(newnode,pos);
                 break;

          case 4:display(head);
            break;
            case 5:exit(0);
            break;


default:printf("invalid choice\n");break;
}
}
}
struct node * insert(struct node *newnode)
{
   if(head==NULL)
     {
        head=newnode;
        newnode->next=head;
     }
     else
     {
        temp=head;
        while(temp->next!=head)
        {
           temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
     }
     return(head);
}
struct node*modify_delete(struct node*head,int pos)
{
      int p;
    if(pos==1)
    {
        temp=head;
        free(temp);

    }


 p=1;
 temp=head;
 while(p!=pos)
 {
 temp1=temp;
 temp=temp->next;
 p++;
 }
 temp1->next=temp->next;
 printf("Node deleted=%s\n",temp->data);
 free(temp);

 return(head);

};
struct node*modify_add(struct node*newnode,int pos)
{
    int p;
 if(pos==1)
 head=insert(newnode);
 else
 {
 p=1;
 temp=head;
 while(p!=pos)
 {
 temp1=temp;
 temp=temp->next;
 p++;
 }
 temp1->next=newnode;
 newnode->next=temp;
 }
 return(head);
};

void display(struct node *head)
{
  if(head==NULL)
     {
        printf("CLL is empty\n");
     }
     else
     {
         temp=head;
         while(temp->next!=head)
         {
            printf("%s->",temp->data);
            temp=temp->next;
         }
         printf("%s->\n",temp->data);
     }
}



