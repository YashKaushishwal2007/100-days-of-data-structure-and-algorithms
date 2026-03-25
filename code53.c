#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    QNode* queue = (QNode*)malloc(1000 * sizeof(QNode));
    int front = 0, rear = 0;

    int hd[1000], val[1000], size = 0;

    int min = 0, max = 0;

    queue[rear++] = (QNode){root, 0};

    while (front < rear) {
        QNode temp = queue[front++];
        Node* curr = temp.node;
        int h = temp.hd;

        hd[size] = h;
        val[size] = curr->data;
        size++;

        if (h < min) min = h;
        if (h > max) max = h;

        if (curr->left)
            queue[rear++] = (QNode){curr->left, h - 1};
        if (curr->right)
            queue[rear++] = (QNode){curr->right, h + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < size; j++) {
            if (hd[j] == i) {
                printf("%d ", val[j]);
            }
        }
        printf("\n");
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    verticalOrder(root);

    free(arr);
    return 0;
}