/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1  */
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue (for level order construction)
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

// Create Node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build Tree from Level Order
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
        struct Node *curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Traversals
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
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
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}