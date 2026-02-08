#include <stdio.h>


int power(int a, int b)
{
    if (b == 0)
        return 1;          

    return a * power(a, b-1);   
}


void display(int result)
{
    printf("%d\n", result);
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    
    int result = power(a, b);


    display(result);

    return 0;
}
