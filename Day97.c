/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

void heapPush(int heap[], int *size, int val)
{
    int i = (*size)++;
    heap[i] = val;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

void heapPop(int heap[], int *size)
{
    heap[0] = heap[--(*size)];

    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }
}

int minMeetingRooms(int intervals[][2], int n)
{
    if (n == 0)
        return 0;

    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[n];
    int heapSize = 0;

    heapPush(heap, &heapSize, intervals[0][1]);

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= heap[0])
        {
            heapPop(heap, &heapSize);
        }

        heapPush(heap, &heapSize, intervals[i][1]);
    }

    return heapSize;
}

int main()
{
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d", minMeetingRooms(intervals, n));

    return 0;
}