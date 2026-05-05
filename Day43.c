/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6 */
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue for level order construction
struct Queue
{
    struct Node *arr[100];
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

void enqueue(struct Queue *q, struct Node *temp)
{
    if (q->rear == 99)
        return;
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = temp;
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

// Create new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build Tree
struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node *root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n)
    {
        struct Node *current = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1)
        {
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Inorder Traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main Function
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    inorder(root);

    return 0;
}