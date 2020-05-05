//Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

//Take a generic tree input where you are first given the data of the node and then its no of children. 
//The input is of preorder form and it is assured that the no of children will not exceed 2.
//The input of the tree is followed by a single integer K.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void print(node *root)
{
    //cout << "reached";
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ",";
    print(root->left);
    print(root->right);
}

void func(node *&root)
{
    int d;
    cin >> d;

    root = new node(d);

    int child;
    cin >> child;

    if (child == 2)
    {
        func(root->left);
        func(root->right);
        return;
    }

    if (child == 1)
    {

        root->right = NULL;
        func(root->left);
        return;
    }

    if (child == 0)
    {
        root->left == NULL;
        root->right = NULL;
        return;
    }
}

int total = 0;

void sum_at_level_k(node *root, int k)
{

    if (root == NULL)
    {
        return;
    }

    if (k < 0)
    {
        return;
    }
    if (k == 0)
    {
        total += root->data;
    }

    sum_at_level_k(root->left, k - 1);
    sum_at_level_k(root->right, k - 1);
}

int main()
{
    node *root = NULL;
    func(root);
    //print(root);

    int level;
    cin >> level;

    
    sum_at_level_k(root, level);
    cout << total;
}
