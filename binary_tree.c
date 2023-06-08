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

Btree *treesearch(Btree **tree, int number)
{
    if ((*tree)->number == number)
    {
        return (*tree);
    }
    else if ((*tree) != NULL)
    {
        if (number < (*tree)->number)
        {
            Btree *aux1 = treesearch(&(*tree)->left, number);
        }
        else
        {
            Btree *aux1 = treesearch(&(*tree)->right, number);
        }
    }
}

Btree *treeremoveNODE(Btree *tree, int object)
{if (tree == NULL)
{
        return tree;
}

    else if (object < tree->number)
    {
        tree->left = treeremoveNODE(tree->left, object);
    }
    else if (object > tree->number)
    {
       tree->left = treeremoveNODE(tree->right, object);
    }
    else
    {
        if (tree->left == NULL)
        {
            Btree *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            Btree *temp = tree->left;
            free(tree);
            return temp;
        }

        Btree *temp = tree;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }
        tree->number = temp->number;

        tree->right = treeremoveNODE(tree->right, object);
    }
        return tree;
}

void treedeleteALL(Btree **tree)
{
    if ((*tree) != NULL)
    {
        treedeleteALL(&(*tree)->left);
        treedeleteALL(&(*tree)->right);
        free((*tree));
    }
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