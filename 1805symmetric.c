#include <stdio.h>
int main() {
    FILE *fp;
    int a[10][10];
    int r,c;
    int i, j;
    int symmetric=1;
    fp = fopen("symmatrix.txt","r");
    fscanf(fp,"%d\n",&r);
    fscanf(fp,"%d",&c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
    fclose(fp);
    if (r!= c)
    {
       printf("matrix is not symmetric ");
       exit(0);
    }
    else
        {
        for (i = 0; i < r; i++)
            {
            for (j = 0; j < c; j++)
            {
                if (a[i][j] != a[j][i])
                {
                    symmetric = 0;
                    break;
                }
            }
            if (symmetric == 0)
            {
                break;
            }
        }
    }
    fp = fopen("symmatrix.txt","w");
    if (symmetric==1)
    {
        printf("The matrix is symmetric.\n");
         printf("matrix is:");
        for (i = 0; i < r; i++)
            {
            for (j = 0; j < c; j++)
            {

                printf("%d\t",a[i][j]);
            }
            printf("\n");
            }
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }
        fclose(fp);
        return 0;
}
