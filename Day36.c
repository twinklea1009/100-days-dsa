/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end.
 Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CircularQueue
{
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct CircularQueue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(struct CircularQueue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
        q->rear->next = q->front;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}

void dequeue(struct CircularQueue *q)
{
    if (q->front == NULL)
        return;

    if (q->front == q->rear)
    {
        free(q->front);
        q->front = q->rear = NULL;
    }
    else
    {
        struct Node *temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

void display(struct CircularQueue *q)
{
    if (q->front == NULL)
        return;

    struct Node *temp = q->front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main()
{
    struct CircularQueue q;
    initQueue(&q);

    int n, m, i, val;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        dequeue(&q);
    }

    display(&q);

    return 0;
}