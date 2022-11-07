#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree
{
    int value;
    struct binaryTree *left;
    struct binaryTree *right;
} bt;

bt *createBT(int val)
{
    bt *temp = (bt *)malloc(sizeof(bt));
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrder(bt *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(bt *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

void inOrder(bt *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

int main()
{
    // printf("anisole");
    bt *ap = createBT(4);
    bt *ap1 = createBT(34);
    bt *ap2 = createBT(23);
    bt *ap3 = createBT(234);
    bt *ap4 = createBT(423);
    bt *ap5 = createBT(1);

    ap->left = ap1;
    ap->right = ap2;
    ap1->left = ap3;
    ap1->right = ap4;
    ap2->right = ap5;

    /*
        4
       / \
     34  23
    /  \   \
   234 423 1

    */
    printf("preOrder = ");
    preOrder(ap);
    printf("\n");
    printf("inOrder = ");
    inOrder(ap);
    printf("\n");
    printf("postOrder = ");
    postOrder(ap);
    return 0;
}
