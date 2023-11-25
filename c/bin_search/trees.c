#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

int getSum (Node *root) {
        if (root = NULL) return 0; // root -> first node
        return root->data + getSUm (root->left) + getSum (root->right);
}
int main () {
        
        return 0;
}