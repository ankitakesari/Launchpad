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

node *build_tree()
{
    //cout << "B";
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = build_tree();
    root->right = build_tree();

    return root;
}

void preorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int count_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (1 + count_nodes(root->left) + count_nodes(root->right));
}

int sum_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (root->data + sum_nodes(root->left) + sum_nodes(root->right));
}

int main()
{
    node *root = build_tree();
    //1 2 3 -1 -1 -1 4 5 -1 -1 6 -1 -1

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    int nodes = count_nodes(root);
    cout << nodes << endl;

    int sum = sum_nodes(root);
    cout << sum << endl;
}