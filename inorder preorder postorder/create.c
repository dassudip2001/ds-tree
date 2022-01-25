#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void main()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 12;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 32;
    p2->left = NULL;
    p2->right = NULL;

    struct node *p3;
    p3 = (struct node *)malloc(sizeof(struct node));
    p3->data = 42;
    p3->left = NULL;
    p3->right = NULL;
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = NULL;
    // printf(p);
}