#include<stdio.h>
#define max 1000
int main()
{
    FILE*fp;
    char arr[max],x;
    int i=0,j,size=0;
    fp=fopen("search.txt","r");
      while(fscanf(fp,"%c",&arr[size])!=EOF)
    {
        size++;

    }

    if(strcmp(arr[i],"bvb"))
    {
       arr[i]=="kle";
    }
    fclose(fp);

         printf("enter the word\n");
    scanf("%s",x);

     fp=fopen("search.txt","w");
      for(i=0;i<size;i++)
      {
          fprintf(fp,"%c\n",arr[i]);
      }
      fclose(fp);
      return 0;

}
