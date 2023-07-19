#include<stdio.h>
void read(char a[10][10]);
void display(char a[10][10]);
void main()
{
      char a[10][10];
      read(a);
      display(a);
}

 void read(char a[10][10])
 {
      int i,j;
    printf("Enter chess characters\n");
    for(i=0;i<4;i++)
    {
         for(j=0;j<8;j++)
         {
             scanf("%s",&a[i][j]);
         }
         printf("\n");

    }
 }
 void display(char a[10][10])
 {

    int i,j;
    printf("Chess elements are\n");
    a[0][0]=

    for(i=0;i<2;i++)
    {
         for(j=0;j<8;j++)
         {
             printf("%s\t",a[i][j]);
         }
       printf("\n");
 }
  printf("\n");
   printf("\n");
    printf("\n");
     printf("\n");
      printf("\n");

 for(i=2;i<4;i++)
    {
         for(j=0;j<8;j++)
         {
             printf("%s\t",a[i][j]);
         }
 }
 }
