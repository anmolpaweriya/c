#include <stdio.h>
#include <stdlib.h>
typedef struct anisole
{
    int value;
    struct BT *left;
    struct BT *right;
} bt;

bt *newNode(int val)
{
    bt *newTemp = (bt *)malloc(sizeof(bt));

    newTemp->value = val;
    newTemp->left = NULL;
    newTemp->right = NULL;
    return newTemp;
}

bt *top = NULL;
int main()
{
    int tempVar;
    printf("Root Node Value :-) ");
    scanf("%d", &tempVar);
    bt *temp = newNode(tempVar);
    temp->value = tempVar;
    temp->left = NULL;
    temp->right = NULL;
    top = temp;

    while (0 == 0)
    {
        printf("\n\n-------------------------------\n\n");
        printf("Choose One Operation --------->");
        printf("\n\t1.) Root Node value");
        printf("\n\t69.) exit");

        printf("\n\nEnter Your Choice :-)");
        scanf("%d", &tempVar);
        switch (tempVar)
        {
        case 1:
            printf("\n\n\nRoot Node Value :-) %d\n\n", top->value);
            break;
        case 69:
            goto end;
            break;
        default:
            printf("\n----------[!]Invalid Choice -------------");
            break;
        }
    }
end:
    printf("\n\nExit ...");
    return 69;
}
