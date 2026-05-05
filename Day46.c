/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications  */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue structure
struct Queue
{
    struct Node *arr[1000];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

void enqueue(struct Queue *q, struct Node *node)
{
    if (q->rear == 999)
        return;

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = node;
}

struct Node *dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return NULL;

    struct Node *temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Level Order Traversal
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        struct Node *current = dequeue(&q);

        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(&q, current->left);

        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    struct Node *nodes[N];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (nodes[i] != NULL)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < N)
                nodes[i]->left = nodes[left];

            if (right < N)
                nodes[i]->right = nodes[right];
        }
    }

    levelOrder(nodes[0]);

    return 0;
}