#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
typedef struct bst
{
    int data;
    struct bst *right;
    struct bst *left;
} node;
void insert_bst(node **root, int item);
void inorder(node *root);
int main()
{
    node *root = NULL;
    int item, ch;

    while (1)
    {
        printf("1.BST insert\n");
        printf("2.BST inorder display\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a new node:");
            scanf("%d", &item);
            insert_bst(&root, item);
            break;
        case 2:
            inorder(root);
            break;
        default:
            exit(0);
        }
    }
}
void insert_bst(node **root, int item)
{
    node *temp;
    if ((*root) == NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = item;
        temp->right = NULL;
        temp->left = NULL;
        (*root) = temp;
        return;
    }
    if (item < (*root)->data)
        insert_bst(&((*root)->left), item);
    else
        insert_bst(&((*root)->right), item);
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}