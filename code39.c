#include <stdio.h>
#include <string.h>

int dq[100];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        dq[front] = x;
    } else if (front > 0) {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
        dq[rear] = x;
    } else {
        dq[++rear] = x;
    }
}

int pop_front() {
    if (isEmpty()) return -1;
    int val = dq[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;
    int val = dq[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return val;
}

int getFront() {
    if (isEmpty()) return -1;
    return dq[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x; scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            int x; scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }

    return 0;
}