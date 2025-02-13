#include "bst.h"

int main() {
    struct tree* new_node1 = bstree_create_node(4);
    struct tree* new_node2 = bstree_create_node(8);
    printf("quest3:\n");
    print_tree(new_node1);
    printf("and ");
    print_tree(new_node2);
    printf("\n");
    free_node(new_node1);
    free_node(new_node2);
    return 0;
}