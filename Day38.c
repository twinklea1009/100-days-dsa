/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front, rear;
} Deque;

void initDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}

int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

void push_front(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

void push_back(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

void pop_front(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
}

void pop_back(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
}

void front(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
    }
    else
    {
        printf("Front: %d\n", dq->arr[dq->front]);
    }
}

void back(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
    }
    else
    {
        printf("Back: %d\n", dq->arr[dq->rear]);
    }
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque dq;
    initDeque(&dq);
    int choice, value;

    while (1)
    {
        printf("\n--- Deque Menu ---\n");
        printf("1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n");
        printf("5. Front\n6. Back\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(&dq, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(&dq, value);
            break;
        case 3:
            pop_front(&dq);
            break;
        case 4:
            pop_back(&dq);
            break;
        case 5:
            front(&dq);
            break;
        case 6:
            back(&dq);
            break;
        case 7:
            display(&dq);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}