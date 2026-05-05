/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
int isRightAssociative(char op) { return op == '^'; }

void infixToPostfix(char *infix)
{
    char postfix[100];
    int k = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];
        if (isalnum(c))
            postfix[k++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(peek()) > 0 &&
                   (precedence(peek()) > precedence(c) ||
                    (precedence(peek()) == precedence(c) && !isRightAssociative(c))))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty())
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("%s\n", postfix);
}

int main()
{
    char infix[100];
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}