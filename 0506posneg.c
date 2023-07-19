#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node  *head,*temp,*temp1,*newnode;
struct node* insert_at_end(struct node *);
struct node* delete_at_beg(struct node *);

void display(struct node *);
main()
{  int ch,n;
    head=NULL;
    FILE *fp,*fp1;
    int array[10],s=0;
    fp=fopen("input.txt","r");
    while(fscanf(fp,"%d",&array[s])!=EOF)
    {
        s++;
        if(head==NULL)
                printf("deleted\n");

            else
            {
                head=delete_at_beg(head);
            }


    }
    fclose(fp);
   fp = fopen("positive.txt","w");
   fp1 = fopen("negative.txt","w");
    for(int i=0;i<s;i++)
    {
        if(array[i]>=0)
        {
            fprintf(fp,"%d\n",array[i]);
        newnode=(struct node*)malloc(sizeof(struct node));
        head=insert_at_end(newnode);
        }
        else
        {
            fprintf(fp1,"%d\n",array[i]);
        newnode=(struct node*)malloc(sizeof(struct node));
        head=insert_at_end(newnode);
        }


    }
    fclose(fp);
    return 0;

}
struct node* insert_at_end(struct node *newnode)
{
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        return(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newnode;
        newnode->next=NULL;
        return(head);

    }
}
struct node* delete_at_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
        if(head->next==NULL)
        {
            printf("node deleted=%d\n",head->data);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
            temp=head;
            head=head->next;
            printf("node deleted=%d\n",temp->data);
            free(temp);
            return(head);

        }
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
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
