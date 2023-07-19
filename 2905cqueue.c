#include<stdio.h>
#include<stdlib.h>
#define max_size 1000
#define MAX 10
struct node
{
    int a[100];
    int front;
    int rear;
}s;
void enqueue(struct node *p,int size);
int dequeue(struct node *p,int x,int size);
int main()
{   FILE *fp;
int arr[max_size],size=0,i;
   struct node *p=&s;int ch; int x,y;
    p->front=-1;
   p->rear=-1;
   fp = fopen("input.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;
       dequeue(p,x,size);
    }
    fclose(fp);

    fp = fopen("output.txt","w");

    for(i=0;i<size;i++)
    {
        fprintf(fp,"%d\n",arr[i]);
       enqueue(p,size);
    }
    fclose(fp);
    return 0;
}
void enqueue(struct node *p,int size)
{
    int m;
    if(p->front==-1 && p->rear==-1)
    {
         p->rear++;
         p->front++;
         p->a[p->rear]=m;
    }
    else if((p->rear+1)%size==p->front)
    {
        printf("Overflow\n");
    }
    else{

        p->rear=(p->rear+1)%size;
        p->a[p->rear]=m;
    }
}
int dequeue(struct node *p,int x,int size)
{

     if(p->front==p->rear)
    {
        x =  p->a[p->front];
         p->front=-1;
          p->rear=-1;
        printf("%d\n",x);

    }
    else{
        x = p->a[p->front];
         p->front=(p->front+1)%size;
         printf("%d\n",x);
    }

}
