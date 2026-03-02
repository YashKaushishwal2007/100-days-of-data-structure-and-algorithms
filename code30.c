#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int c, int e)
{
    struct Node* temp = createNode(c, e);

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

void printPolynomial(struct Node* head)
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    int n, c, e;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }

    printPolynomial(head);

    return 0;
}