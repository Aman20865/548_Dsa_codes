#include<stdio.h>
void recursion(int n);
void main()
{
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    recursion(n);
}
void recursion(int n)
{
    if(n>0)
    {
        for(int i=1;i<n;i=i*2)
        {
            printf("%d\t",n);
        }
        recursion(n-1);
    }
}

