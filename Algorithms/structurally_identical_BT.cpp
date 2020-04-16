#include <iostream>
#include <string>
#include <cmath>
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

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

node *build_tree(node *root)
{

    int value;
    cin >> value;

    root = new node(value);

    string child;

    cin >> child;

    if (child == "true")
    {
        root->left = build_tree(root->left);
    }

    cin >> child;
    if (child == "true")
    {
        root->right = build_tree(root->right);
    }

    return root;
}
bool structurally_identical(node *A, node *B)
{
    if (A == NULL && B == NULL)
    {
        return true;
    }

    if (A != NULL && B != NULL)
    {
        bool left = structurally_identical(A->left, B->left);
        bool right = structurally_identical(A->right, B->right);

        return (left && right);
    }

    return false;
}
int main()
{

    node *root1 = NULL;
    root1 = build_tree(root1);
    //print(root);

    node *root2 = NULL;
    root2 = build_tree(root2);

    bool identical = structurally_identical(root1, root2);
    if (identical)
    {
        cout << "true";
    }

    else
    {
        cout << "false";
    }
}