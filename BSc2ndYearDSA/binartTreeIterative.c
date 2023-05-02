#include <stdio.h>
#include <stdlib.h>
// #include "binaryTree.c"

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

typedef struct linkedList
{
    struct binaryTree *value;
    struct linkedList *next;
} ll;

ll *top = NULL;

void llPush(bt *val)
{
    ll *templl = (ll *)malloc(sizeof(ll));
    templl->value = val;
    templl->next = top;
    top = templl;
}
bt *llPop()
{
    bt *tempb;
    if (top == NULL)
    {
        return NULL;
    }
    tempb = top->value;
    ll *templl = top;
    top = top->next;
    free(templl);
    return tempb;
}

void llTraverse()
{
    ll *templl;
    templl = top;
    while (templl != NULL)
    {
        printf("\n%d", templl->value->value);
        templl = templl->next;
    }
}
void preOrder(bt *temp)
{

    while (temp != NULL)
    {
        // preOrder
        printf("%d ", temp->value);
        if (temp->right != NULL)
        {

            llPush(temp->right);
        }

        if (temp->left == NULL)
        {
            temp->left = llPop();
            // llTraverse();
        }

        temp = temp->left;
    }
}

void inOrder(bt *root)
{
    while (1)
    {
        if (root != NULL)
        {
            llPush(root);
            root = root->left;
        }
        else
        {
            if (top != NULL)
            {
                root = llPop();
                printf("%d ", root->value);
                root = root->right;
            }
            else
            {
                break;
            }
        }
    }
}

void postOrder(bt *temp)
{
    // bt *temp2 = NULL;
    // while (temp != NULL || top != NULL)

    //     if (temp == NULL || temp == temp2)
    //     {

    //         if (top->value->right != NULL)
    //         {
    //             temp = top->value->right;
    //         }
    //         else
    //         {
    //             printf("%d ", llPop()->value);
    //             temp = temp2 = top->value;
    //         }
    //     }
    //     else
    //     {
    //         llPush(temp);
    //         temp = temp->left;
    //     }

    int arr[69], len = 0;
    while (top != NULL || temp != NULL)
    {

        // printf("%d ", temp->value);
        arr[len++] = temp->value;   // storing into array to reverse the result 
        if (temp->left != NULL) 
        {                           // check Left Node
            llPush(temp->left);
        }

        if (temp->right != NULL)
        {                           // check Right Node
            temp = temp->right;
        }
        else
        {
            temp = llPop();
        }
    }

    while (len > 0)
    {                               // final result
        printf("%d ", arr[--len]);
    }
}

int main()
{

    // printf("Anisole");
    bt *ap = createBT(4);
    bt *ap1 = createBT(34);
    bt *ap2 = createBT(23);
    bt *ap3 = createBT(234);
    bt *ap4 = createBT(423);
    bt *ap5 = createBT(1);
    bt *ap6 = createBT(69);

    ap->left = ap1;
    ap->right = ap2;
    ap1->left = ap3;
    ap2->left = ap4;
    ap2->right = ap5;
    ap4->right = ap6;
    /*
        4
       / \
     34  23
    /   /  \
   234 423 1
        \
        69
    */

    // preOrder(ap);
    // inOrder(ap);
    postOrder(ap);

    return 0;
}
