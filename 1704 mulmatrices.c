#include<stdio.h>
void read(int *p1,int*p2,int r1,int c1,int r2,int c2);
void display(int *p1,int*p2,int r1,int c1,int r2,int c2);
void multiply(int *p1[10][20],int*p2[10][20],int r1,int c1,int r2,int c2);
void main()
{
    int a[10][20],b[10][20];
    int *p1=&a[10][20],*p2=&b[10][20], r1,c1, r2, c2;
    printf("Enter the rows and coloumns of 1st and 2nd matrix\n");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    read(p1,p2,r1,c1,r2,c2);
    display(p1,p2,r1,c1,r2,c2);
    if(c1==r2)
    {
      multiply(p1,p2,r1,c1,r2,c2);
    }
    else
    {
        printf("cannot multiply\n");
    }





}
void read(int*p1,int*p2,int r1,int c1,int r2,int c2)
{
    int i,j;
    printf("enter 1st elements\n");
    for (i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",p1);
            p1++;

        }

    }

    printf("enter 2nd elements\n");
    for (i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",p2);
            p2++;

        }
    }
}
void display(int*p1,int*p2,int r1,int c1,int r2,int c2)
{
    int i,j;
    printf("entered 1st elements\n");
    for (i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",*p1);
            p1++;
        }
        printf("\n");
    }

    printf("entered 2nd elements\n");
    for (i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",*p2);
            p2++;
        }
        printf("\n");
    }
}
void multiply(int *p1[10][20],int*p2[10][20],int r1,int c1,int r2,int c2)
{
    int i,j,k,s[10][20];
     printf("product is\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++);
        {
                for(k=0;k<r1;k++)
                {


            s[i][j]=(*p1[i][k])*(*p2[k][j]);
            printf("%d",s[i][j]);
                }
        }
        printf("\n");
    }
}
