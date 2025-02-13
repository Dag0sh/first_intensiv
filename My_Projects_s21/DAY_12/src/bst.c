#include "bst.h"

struct tree* bstree_create_node(int a) {
    struct tree* new_node = (struct tree*)malloc(sizeof(struct tree));
    if (new_node != NULL) {
        new_node->numb = a;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

void print_tree(struct tree* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->numb);
    print_tree(root->left);
    print_tree(root->right);
}

void free_node(struct tree* new_node) {
    if (new_node->right != NULL) {
        free_node(new_node->right);
    }
    if (new_node->left != NULL) {
        free_node(new_node->left);
    }
    free(new_node);
}

void inseert(struct tree** root, int num) {
    if (root == NULL) {
        *root = bstree_create_node(num);
        return;
    }
    if ((*root)->numb > num) {
        inseert(&(*root)->left, num);
    } else {
        inseert(&(*root)->right, num);
    }
}