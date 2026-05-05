/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications     */
#include <stdio.h>
#include <stdlib.h>

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

// Insert into BST
struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct TreeNode *searchBST(struct TreeNode *root, int key)
{
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Inorder (for display)
void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    struct TreeNode *root = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("BST (Inorder): ");
    inorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    struct TreeNode *result = searchBST(root, key);

    if (result != NULL)
        printf("Value %d found in BST.\n", key);
    else
        printf("Value %d not found in BST.\n", key);

    return 0;
}