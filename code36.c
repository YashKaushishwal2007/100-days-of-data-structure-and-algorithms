#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (rear == NULL) {
        newNode->next = newNode;
        rear = newNode;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (rear == NULL) return;

    struct Node* temp = rear->next;

    if (rear == rear->next) {
        rear = NULL;
    } else {
        rear->next = temp->next;
    }

    free(temp);
}

void display() {
    if (rear == NULL) return;

    struct Node* temp = rear->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();
    return 0;
}