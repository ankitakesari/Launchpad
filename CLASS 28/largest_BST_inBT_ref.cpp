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

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ",";
    print(root->left);
    print(root->right);
}

class nodeHelper
{
public:
    bool isBST;
    int maximum;
    int minimum;
    int size;

    nodeHelper()
    {
        isBST = true;
        maximum = INT_MIN;
        minimum = INT_MAX;
        size = 0;
    }
};

nodeHelper *largestBSTinBT(node *root)
{
    if (root == NULL)
    {
        //returns pointer to a object
        nodeHelper *a = new nodeHelper();
        return a;
    }

    nodeHelper *leftTree = largestBSTinBT(root->left);
    nodeHelper *rightTree = largestBSTinBT(root->right);
    nodeHelper *curr = new nodeHelper();
    if (leftTree->maximum <= root->data and rightTree->minimum > root->data and leftTree->isBST and rightTree->isBST)
    {
        curr->isBST = true;
        curr->maximum = max(rightTree->maximum, root->data);
        curr->minimum = min(leftTree->minimum, root->data);
        curr->size = leftTree->size + rightTree->size + 1;
    }
    else
    { //when curr tree is not a bst
        curr->isBST = false;
        curr->size = max(leftTree->size, rightTree->size);
    }
    return curr;
}

int main()
{
    node *root = buildTree();
    print(root);
    cout << endl;

    nodeHelper *ans = largestBSTinBT(root);

    cout << ans->size;
}