#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int n)
{
    if (n <= 0)
        return NULL;

    int value;
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        temp = createNode(value);

        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    return head;
}

struct Node* rotateRight(struct Node* head, int n, int k)
{
    if (head == NULL || k == 0)
        return head;

    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    temp->next = head;

    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, k;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    printList(head);

    return 0;
}