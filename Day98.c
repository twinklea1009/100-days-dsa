/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return ((int *)a)[0] - ((int *)b)[0];
}

int **merge(int intervals[][2], int n, int *returnSize)
{
    if (n == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int **result = (int **)malloc(n * sizeof(int *));
    int index = 0;

    int start = intervals[0][0];
    int end = intervals[0][1];

    // Step 2: Merge intervals
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= end)
        {
            // Overlapping
            if (intervals[i][1] > end)
                end = intervals[i][1];
        }
        else
        {
            // No overlap → store previous
            result[index] = (int *)malloc(2 * sizeof(int));
            result[index][0] = start;
            result[index][1] = end;
            index++;

            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Add last interval
    result[index] = (int *)malloc(2 * sizeof(int));
    result[index][0] = start;
    result[index][1] = end;
    index++;

    *returnSize = index;
    return result;
}

int main()
{
    int intervals[][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = 4;

    int returnSize;
    int **merged = merge(intervals, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d, %d] ", merged[i][0], merged[i][1]);
    }

    return 0;
}