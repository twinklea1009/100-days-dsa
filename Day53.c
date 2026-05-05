/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root.
 Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct QueueItem
{
    struct Node *node;
    int hd;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node *root = createNode(arr[0]);
    struct Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear)
    {
        struct Node *temp = queue[front++];

        if (i < n && arr[i] != -1)
        {
            temp->left = createNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            temp->right = createNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node *root)
{
    if (root == NULL)
        return;

    int col[2000][1000];
    int count[2000] = {0};

    int offset = 1000;
    int minHD = 0, maxHD = 0;

    struct QueueItem q[1000];
    int front = 0, rear = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while (front < rear)
    {
        struct QueueItem curr = q[front++];

        int index = curr.hd + offset;
        col[index][count[index]++] = curr.node->data;

        if (curr.hd < minHD)
            minHD = curr.hd;

        if (curr.hd > maxHD)
            maxHD = curr.hd;

        if (curr.node->left != NULL)
        {
            q[rear].node = curr.node->left;
            q[rear].hd = curr.hd - 1;
            rear++;
        }

        if (curr.node->right != NULL)
        {
            q[rear].node = curr.node->right;
            q[rear].hd = curr.hd + 1;
            rear++;
        }
    }

    for (int i = minHD; i <= maxHD; i++)
    {
        int index = i + offset;

        for (int j = 0; j < count[index]; j++)
        {
            printf("%d ", col[index][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}