/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>

void insertionSort(float bucket[], int size)
{
    for (int i = 1; i < size; i++)
    {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    float arr[1000];
    float bucket[1000][1000];
    int count[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);

        int index = arr[i] * n;
        bucket[index][count[index]++] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        insertionSort(bucket[i], count[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            printf("%.2f ", bucket[i][j]);
        }
    }

    return 0;
}