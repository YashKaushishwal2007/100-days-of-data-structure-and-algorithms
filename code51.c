#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);
    return root;
}

int main() {
    int n, x, n1, n2;
    scanf("%d", &n);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

    Node* res = lca(root, n1, n2);
    if (res) printf("%d", res->data);

    return 0;
}