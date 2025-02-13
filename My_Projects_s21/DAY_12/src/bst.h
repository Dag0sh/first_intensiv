#ifndef BSTH_H
#define BSTH_H
#include <stdio.h>
#include <stdlib.h>

struct tree {
    struct tree *left;
    struct tree *right;
    int numb;
};

struct tree *bstree_create_node(int a);
void print_tree(struct tree *root);
void free_node(struct tree *new_node);
void inseert(struct tree **root, int num);

#endif