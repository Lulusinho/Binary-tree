#include <stdio.h>
#include <stdlib.h>

struct binary_tree
{
    int number;
    struct binary_tree *left;
    struct binary_tree *right;

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
    {

        treeinsert(&(*tree)->left, number);
    }
    else
        treeinsert(&(*tree)->right, number);
}

void treesearch(Btree **tree, int number)
{
    if ((*tree)->number == number)
    {
        printf("%d", (*tree)->number);
    }
    else if ((*tree) != NULL)
    {
        if (number < (*tree)->number)
            treesearch(&(*tree)->left, number);
        else
            treesearch(&(*tree)->right, number);
    }
}

int treeremove(Btree **tree, int number)
{
}

int treeheight(Btree **tree)
{

    if ((*tree) == NULL)
        return 0;

    int left = treeheight(&(*tree)->left);
    int right = treeheight(&(*tree)->right);

    if (right >= left)
    {
        return right + 1;
    }
    else
    {
        return left + 1;
    }
}

void treepreorder(Btree **tree)
{
    if ((*tree) != NULL)
    {
        printf("|%d |", (*tree)->number);
        treepreorder(&(*tree)->left);
        treepreorder(&(*tree)->right);
    }
}

void treeorder(Btree **tree)
{
    if ((*tree) != NULL)
    {
        treeorder(&(*tree)->left);
        printf("|%d |", (*tree)->number);
        treeorder(&(*tree)->right);
    }
}

void treepostorder(Btree **tree)
{
    if ((*tree) != NULL)
    {
        treepostorder(&(*tree)->left);
        treepostorder(&(*tree)->right);
        printf("|%d |", (*tree)->number);
    }
}