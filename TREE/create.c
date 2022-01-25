#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *create(struct node *root, int val)
{
    if (root == NULL)
        return createnode(val);
    if (root->data < val)
        root->right = create(root->right, val);
    else if (root->data > val)
        root->left = create(root->left, val);
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = create(root, 100);
    root = create(root, 10);
    root = create(root, 110);
    root = create(root, 40);
    root = create(root, 30);
    root = create(root, 120);
    inorder(root);
    return 0;
}