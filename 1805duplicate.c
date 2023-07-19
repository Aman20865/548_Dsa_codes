#include <stdio.h>
void duplicate(int arr[], int size);
void main() {
    int arr[20];
    int i;
    printf("Enter 20 elements:\n");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
    }
    duplicate(arr,20);
}

void duplicate(int arr[], int size)
{
    int i, j;
    int frequency[size];
    FILE *outputFile = fopen("output.txt", "w");

    for (i = 0; i < size; i++)
    {
        frequency[i] = -1;
    }


    for (i = 0; i < size; i++)
        {
        int count = 1;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                frequency[j] = 0;
            }
        }
        if (frequency[i]!= 0)
        {
            frequency[i]=count;
        }
    }

    fprintf(outputFile, "Duplicates and their frequencies:\n");
    for (i=0;i<size;i++)
        {
        if (frequency[i]>1)
        {
            fprintf(outputFile, "%d occurs %d times\n", arr[i], frequency[i]);
        }
    }

    fclose(outputFile);
}
