/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    int val = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char *expr)
{
    char *token = strtok(expr, " ");
    while (token != NULL)
    {
        // Operand (integer, possibly negative)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            switch (token[0])
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                push(a / b);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main()
{
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}