/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30 */

#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i)
{
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i])
        {
            swap(&heap[p], &heap[i]);
            i = p;
        }
        else
            break;
    }
}

void heapifyDown(int i)
{
    while (1)
    {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < size && heap[l] < heap[s])
            s = l;
        if (r < size && heap[r] < heap[s])
            s = r;
        if (s != i)
        {
            swap(&heap[i], &heap[s]);
            i = s;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek()
{
    if (size == 0)
        return -1;
    return heap[0];
}

int extractMin()
{
    if (size == 0)
        return -1;
    int m = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return m;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0)
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
        else if (strcmp(op, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
    }
    return 0;
}