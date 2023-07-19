#include<stdio.h>

int main()
{
    FILE*fp;
    int arr[3][3],i,j,temp,size=0;
    fp=fopen("transpose.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;

    }
    fclose(fp);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    fp=fopen("transpose.txt","w");
      for(i=0;i<3;i++)
      {  for(j=0;j<3;j++)
          {
              fprintf(fp,"%d\t",arr[j][i]);
          }
        printf("\n");
      }
      fclose(fp);
      return 0;
}
