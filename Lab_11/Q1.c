#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int isValidBSTUtil(struct Node* root, long* prev) {
    if (root == NULL)
        return 1;

    
    if (!isValidBSTUtil(root->left, prev))
        return 0;

    
    if (root->data <= *prev)
        return 0;

    
    *prev = root->data;

    
    return isValidBSTUtil(root->right, prev);
}


int isValidBST(struct Node* root) {
    long prev = LONG_MIN;
    return isValidBSTUtil(root, &prev);
}


int main() {

    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(8);

    if (isValidBST(root))
        printf("The tree is a valid BST.\n");
    else
        printf("The tree is NOT a valid BST.\n");

    return 0;
}
