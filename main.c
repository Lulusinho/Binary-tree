#include <stdio.h>
#include<stdlib.h>
#include "binary_tree.c"

int main(int argc, char *argv){

    Btree *tree = NULL;

    treeinsert(&tree, 10);
    treeinsert(&tree, 22);
    treeinsert(&tree, 77);
    treeinsert(&tree, 44);
    treeinsert(&tree, 32);
    treeinsert(&tree, 54);
    treeinsert(&tree, 1);
    treeinsert(&tree, 0);

    printf("\t Display of the binary tree:\n");
    printf("preorder:\n ");
    treepreorder(&tree);
    printf("\norder:\n ");
    treeorder(&tree);
    printf("\npostorder:\n ");
    treepostorder(&tree);
    printf("\n");


    printf("\n The height of this tree: %d", treeheight(&tree));
    
    return 0;
}