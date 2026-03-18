#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; 
    return head;
}


struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node* head = NULL;
    struct node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct node* newNode;

        if (l1->data <= l2->data) {
            newNode = createNode(l1->data);
            l1 = l1->next;
        } else {
            newNode = createNode(l2->data);
            l2 = l2->next;
        }

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (l1 != NULL) {
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

    return head;
}


void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m, x;
    struct node *list1 = NULL, *list2 = NULL, *merged = NULL;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    
    merged = mergeLists(list1, list2);

    
    printList(merged);

    return 0;
}