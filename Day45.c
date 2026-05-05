/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3                */
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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main()
{
    int N;
    scanf("%d", &N);

    if (N == 0)
    {
        printf("0");
        return 0;
    }

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if (arr[0] == -1)
    {
        printf("0");
        return 0;
    }

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
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < N)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < N)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    printf("%d", height(nodes[0]));

    return 0;
}