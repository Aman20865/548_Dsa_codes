#include<stdio.h>
#define max 1000

int main()
{
    FILE*fp;
    int arr[max],i,j,temp,size=0;
    fp=fopen("sort.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;

    }
    fclose(fp);
    for(i=0;i<size-1;i++)
    {
          for(j=0;j<size-1;j++)
          {
              if(arr[j]>arr[j+1])
                 {
                     temp=arr[j];
                     arr[j]=arr[j+1];
              arr[j+1]=temp;
                 }
          }
    }
    fp=fopen("sort.txt","w");
      for(i=0;i<size;i++)
      {
          fprintf(fp,"%d\n",arr[i]);
      }
      fclose(fp);
      return 0;

}
