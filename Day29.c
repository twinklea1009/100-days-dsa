/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *rotateRight(struct Node *head, int k, int n)
{
    if (head == NULL || k == 0 || k % n == 0)
        return head;
    struct Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;
    int steps = n - (k % n);
    struct Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;
    struct Node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, k;
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &k);
    head = rotateRight(head, k, n);
    printList(head);
    return 0;
}