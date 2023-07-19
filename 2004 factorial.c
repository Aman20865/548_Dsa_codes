#include<stdio.h>
int fact(int n);
void main()
{
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("%d",fact(n));


}
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    int f=n*fact(n-1);
    return ;
}
