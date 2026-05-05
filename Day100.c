/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Pair;

void mergeSort(Pair arr[], int left, int right, int ans[])
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, ans);
    mergeSort(arr, mid + 1, right, ans);

    int n = right - left + 1;
    Pair temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;
    int countRight = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j].value < arr[i].value)
        {
            countRight++;
            temp[k++] = arr[j++];
        }
        else
        {
            ans[arr[i].index] += countRight;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        ans[arr[i].index] += countRight;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < n; x++)
    {
        arr[left + x] = temp[x];
    }
}

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;

    int *ans = (int *)calloc(numsSize, sizeof(int));
    Pair *arr = (Pair *)malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++)
    {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, ans);

    free(arr);
    return ans;
}