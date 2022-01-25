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
void main()
{
    struct node *n = create(4);
    struct node *n1 = create(1);
    struct node *n2 = create(6);
    struct node *n3 = create(5);
    struct node *n4 = create(5);
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    pre(n);
}