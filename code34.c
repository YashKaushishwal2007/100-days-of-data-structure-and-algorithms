#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) exit(1);
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char exp[100];
    fgets(exp, sizeof(exp), stdin);
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}