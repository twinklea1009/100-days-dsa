/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications    */
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create node
struct TreeNode *createNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Count leaf nodes
int countLeaves(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Number of leaf nodes: 0\n");
        return 0;
    }

    int arr[n];
    printf("Enter nodes in level order (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Create nodes array
    struct TreeNode *nodes[n];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Link nodes
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL)
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct TreeNode *root = nodes[0];

    int result = countLeaves(root);

    printf("Number of leaf nodes: %d\n", result);

    return 0;
}