#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int countLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;

    int leftCount = countLeafNodes(root->left);
    int rightCount = countLeafNodes(root->right);

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leftCount + rightCount;
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("%d", countLeafNodes(root));
    return 0;
}