/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.  */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
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

void rightView(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++)
        {
            struct Node *temp = queue[front++];

            if (i == levelSize - 1)
                printf("%d ", temp->data);

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }
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

    rightView(root);

    return 0;
}