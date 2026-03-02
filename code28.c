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

struct Node* createCircularList(int n)
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

    last->next = head;
    return head;
}

void traverseCircularList(struct Node* head)
{
    if (head == NULL)
        return;

    struct Node* temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);
    traverseCircularList(head);

    return 0;
}