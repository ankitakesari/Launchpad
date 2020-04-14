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

node *insert(node *root, int d)
{
    if (root == NULL)
    {

        root = new node(d);
        return root;
    }

    if (d <= root->data)
    {
        root->left = insert(root->left, d);
    }

    else
    {
        root->right = insert(root->right, d);
    }

    return root;
}

node *buildBST()
{
    node *root = NULL;
    int d;
    cin >> d;

    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }

    return root;
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

class LinkedList
{
public:
    node *head;
    node *tail;
};

LinkedList flat_BST(node *root)
{
    LinkedList ans;
    if (root == NULL)
    {
        ans.head = ans.tail = NULL;
        return ans;
    }

    else if (root->left == NULL && root->right == NULL)
    {
        ans.head = ans.tail = root;
        return ans;
    }

    else if (root->left != NULL && root->right == NULL)
    {
        LinkedList left_ll = flat_BST(root->left);
        left_ll.tail->right = root;
        ans.head = left_ll.head;
        ans.tail = ans.tail;
        return ans;
    }

    else if (root->right != NULL && root->left == NULL)
    {
        LinkedList right_ll = flat_BST(root->right);
        root->right = right_ll.head;
        ans.head = root;
        ans.tail = right_ll.tail;
        return ans;
    }

    else if (root->right != NULL && root->left != NULL)
    {
        LinkedList left_ll = flat_BST(root->left);
        LinkedList right_ll = flat_BST(root->right);
        left_ll.tail->right = root;
        root->right = right_ll.head;
        ans.head = left_ll.head;
        ans.tail = right_ll.tail;
        return ans;
    }
}

int main()
{
    node *root = buildBST();

    LinkedList ll = flat_BST(root);

    node *l = ll.head;
    while (l)
    {
        cout << l->data << ", ";
        l = l->right;
    }

    return 0;
}