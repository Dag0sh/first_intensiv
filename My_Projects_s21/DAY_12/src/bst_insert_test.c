#include "bst.h"

int main() {
    struct tree* new_node1 = bstree_create_node(4);
    new_node1->right = bstree_create_node(2);
    new_node1->left = bstree_create_node(35);
    struct tree* new_node2 = bstree_create_node(8);
    new_node2->right = bstree_create_node(6);
    new_node2->left = bstree_create_node(25);
    printf("quest4:\n");
    print_tree(new_node1);
    printf("\n");
    print_tree(new_node2);
    free_node(new_node1);
    free_node(new_node2);
    return 0;
}