#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define max 1000
typedef struct stack
{
    int data[MAX];
    int top;
}stack;a;
void push(stack *s);
int pop(stack*s);
int main()
{
    stack *s=&a;
    int ch;
    s->top=-1;
    FILE*fp;
    int m;
    int arr[max],i,j,temp,size=0;
    fp=fopen("stack.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        pop(s);
        size++;

    }
    fclose(fp);


    fp=fopen("stackfile.txt","w");
      for(i=0;i<size;i++)
      {
          m=arr[i];
          fprintf(fp,"%d\n",m);
          push(s);
      }
      fclose(fp);


      fp=fopen("push.txt","w");
      for(i=0;i<size;i++)
      {
          m=arr[i];
          fprintf(fp,"%d\n",m);
          push(s);
      }
      fclose(fp);
      return 0;
    }

void push(stack *s)
{
    if(s->top<MAX-1)
    {


    s->top++;

    }
else
    {
        printf("stack overflow\n");
    }


}
int pop(stack*s)
{

for(int i=0;i<s->top;i++)
{

    printf("%d",s->data[i]);
    printf("\n");
}

    s->top--;


}
