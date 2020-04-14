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

int min_val(int a, int b)
{
    if (a <= b)
    {
        return a;
    }

    else
        b;
}

int max_val(int a, int b)
{
    if (a >= b)
    {
        return a;
    }

    else
        b;
}

node *insert(node *root, int d)
{
    if (root == NULL)
    {
        //wrong: root->data=d;
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

    //made mistake here (forgot to return)
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

    //forgot to return
    return root;
}

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

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (key <= root->data)
    {
        return search(root->left, key);
    }

    else
    {
        return search(root->right, key);
    }
}

node *inorder_successor(node *root, int key)
{

    node *target = search(root, key);
    if (target == NULL)
    {
        return NULL;
    }

    if (target->right)
    {
        node *temp = target->right;

        while (temp->left)
        {
            temp = temp->left;
        }

        return temp;
    }

    else
    {
        node *ancestor = NULL;
        node *successor = root;

        while (successor->data != target->data)
        {

            if (successor->data >= target->data)
            {
                ancestor = successor;
                successor = successor->left;
            }

            else
            {
                successor = successor->right;
            }
        }
        return ancestor;
    }
}

node *pred = NULL;
node *A = NULL;
node *B = NULL;

void swapped_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    swapped_tree(root->left);

    if (pred != NULL && root->data < pred->data)
    {
        B = root;
        if (A == NULL)
        {
            A = pred;
        }

        else
        {
            return;
        }
    }

    pred = root;
    swapped_tree(root->right);
}

void swap(node *a, node *b)
{
    node *temp = new node(a->data);
    a->data = b->data;
    b->data = temp->data;
}

node *recover_BST(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    swapped_tree(root);
    swap(A, B);
}

int no_of_BST(int N)
{
    if (N == 0)
    {
        return 1;
    }

    int total_trees = 0;
    for (int i = 1; i <= N; i++)
    {
        total_trees += no_of_BST(i - 1) * no_of_BST(N - i);
    }

    return total_trees;
}

int main()
{
    // node *root = buildTree();

    // node *succ = inorder_successor(root, 16);

    // cout << succ->data;

    // print(root);
    // cout << endl;
    // recover_BST(root);
    // print(root);

    int no_of_trees = no_of_BST(5);
    cout << no_of_trees;
}