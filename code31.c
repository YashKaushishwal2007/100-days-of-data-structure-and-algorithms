#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d\n", stack[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, op, value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &value);
            push(value);
        }
        else if(op == 2)
        {
            pop();
        }
        else if(op == 3)
        {
            display();
        }
    }

    return 0;
}