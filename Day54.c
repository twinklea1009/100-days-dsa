/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.  */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
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

void zigzagTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[1000];
    int front = 0, rear = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear)
    {
        int levelSize = rear - front;
        int level[1000];

        for (int i = 0; i < levelSize; i++)
        {
            struct Node *temp = queue[front++];

            int index;
            if (leftToRight)
                index = i;
            else
                index = levelSize - 1 - i;

            level[index] = temp->data;

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        for (int i = 0; i < levelSize; i++)
        {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
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

    zigzagTraversal(root);

    return 0;
}