/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

struct Node *findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            p1 = p1->next;
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
            p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL;
    struct Node *tail1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (head1 == NULL)
        {
            head1 = newNode;
            tail1 = newNode;
        }
        else
        {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL;
    struct Node *tail2 = NULL;
    for (int i = 0; i < m; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (head2 == NULL)
        {
            head2 = newNode;
            tail2 = newNode;
        }
        else
        {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    struct Node *inter = findIntersection(head1, head2);
    if (inter != NULL)
        printf("%d\n", inter->data);
    else
        printf("No Intersection\n");

    return 0;
}