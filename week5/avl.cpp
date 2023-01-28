#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height = 1;
};

class AVL
{
    node *root;

public:
    AVL()
    {
        root = NULL;
    }

    node *leftRotation(node *x)
    {
        node *y = x->right;
        node *T = y->left;
        x->right = T;
        y->left = x;
        x->height = max(x->left->height, x->right->height) + 1;
        y->height = max(y->left->height, y->right->height) + 1;
        return y;
    }

    node *leftRotation(node *x)
    {
        node *y = x->left;
        node *T = y->right;
        x->left = T;
        y->right = x;
        x->height = max(x->left->height, x->right->height) + 1;
        y->height = max(y->left->height, y->right->height) + 1;
        return y;
    }
};
main()
{
}