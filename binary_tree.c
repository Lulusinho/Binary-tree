#include <stdio.h>
#include <stdlib.h>

struct binary_tree
{
    int number;
    struct binarie_tree *left;
    struct binarie_tree *right;

} typedef Btree;

Btree *allocnode(int num)
{
    Btree *node = (Btree *)malloc(sizeof(Btree));
    node->number = num;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void treeinsert(Btree **tree, int number)
{

    if ((*tree) == NULL)
    {
        Btree *node = allocnode(number);
        (*tree) = node;
    }
    else if (number < (*tree)->number)
        treeinsert((*tree)->left, number);
    else
        treeinsert((*tree)->right, number);
}

void treedisplay(Btree **tree){
    treedisplay((*tree)->left);
    treedisplay((*tree)->right);
    printf("|%d |", (*tree)->number);
}