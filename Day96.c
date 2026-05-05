/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/
#include <stdio.h>

long long merge(int arr[], int left, int mid, int right)
{
    int temp[1000];
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];

    return invCount;
}

long long mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld", mergeSort(arr, 0, n - 1));

    return 0;
}