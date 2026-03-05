#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void display()
{
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    // push n elements
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        pop();
    }

    
    display();

    return 0;
}