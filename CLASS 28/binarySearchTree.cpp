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

node *delete_in_BST(node *root, int key)
{
    //cout << root->data << endl;
    if (root == NULL)
    {
        //cout << "1";
        return NULL;
    }

    if (key < root->data)
    {
        // cout << "2";
        root->left = delete_in_BST(root->left, key);
    }

    else if (key > root->data)
    {
        //cout << "3";
        root->right = delete_in_BST(root->right, key);
    }

    else
    { //found
        //if need to delete all occurences of target then...make this else into an independent IF
        //also if(key<=root->data){  // as <= elements are in Left subtree
        //root->left = delete_in_BST(root->left,target)
        //}

        if (root->left == NULL && root->right == NULL)
        {

            node *temp = root;
            delete (temp);
            return NULL;
        }

        //if left child is null
        else if (root->left == NULL)
        {

            node *temp = root->right;
            delete (root);
            return temp;
        }

        //if right child is null
        else if (root->right == NULL)
        {

            node *temp = root->left;
            delete (root);
            return temp;
        }

        else
        {
            //finding max in left subtree

            node *temp = root->left;

            while (temp->right)
            {
                temp = temp->right;
            }

            root->data = temp->data;

            root->left = delete_in_BST(root->left, root->data);
            return root;
        }
    }

    return root;
}

//minimum element in the tree
node *min_node(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL)
    {
        return root;
    }

    return (min_node(root->left));
}

//maximum element in the tree
node *max_node(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->right == NULL)
    {
        return root;
    }

    return (max_node(root->right));
}

bool isBST(node *root, int minn, int maxx)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= minn && root->data <= maxx && isBST(root->left, minn, root->data) && isBST(root->right, root->data, maxx))
    {
        return true;
    }

    return false;
}

int main()
{
    // node *root = buildBST();
    // print(root);
    // cout << endl;
    // node *found = search(root, 11);

    // if (found)
    // {
    //     cout << "found";
    // }

    // else
    // {
    //     cout << "not found";
    // }

    // node *root2 = delete_in_BST(root, 9);
    // print(root2);

    // node *max = max_node(root);
    // cout << max->data;

    // node *root2 = buildTree();
    // print(root2);
    // cout << endl;

    // bool bst = isBST(root2, INT_MIN, INT_MAX);

    // if (bst)
    // {
    //     cout << "tree is bst";
    // }

    // else
    // {
    //     cout << "tree is not a bst";
    // }
}