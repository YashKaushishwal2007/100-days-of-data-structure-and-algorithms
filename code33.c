#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}