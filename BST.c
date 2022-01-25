#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void pre(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        pre(root->left);
        pre(root->right);
    }
}
void post(struct node *root)
{
    if (root != NULL)
    {

        post(root->left);
        post(root->right);
        printf("%d", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root)
{
    struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
void main()
{
    struct node *n = create(4);
    struct node *n1 = create(1);
    struct node *n2 = create(6);
    struct node *n3 = create(5);
    struct node *n4 = create(2);
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    // pre(n);
    // printf("\n");
    // post(n);
    // printf("\n");
    // inorder(n);
    printf("%d", isBST(n));
    printf("\n");
    inorder(n);
}