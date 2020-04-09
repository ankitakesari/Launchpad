#include <iostream>
#include <queue>
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

int max_val(int a, int b)
{
    if (a >= b)
    {
        return a;
    }

    else
    {
        return b;
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return (max_val(height(root->left), height(root->right)) + 1);
}

void print_k_level(node *root, int k)
{
    //cout << "level: " << k << endl;

    if (root == NULL)
    {
        //this termination condition should be above other
        return;
    }
    if (k == 0)
    {
        cout << root->data << ",";
        return;
    }

    print_k_level(root->left, k - 1);
    //cout << "left returned" << endl;
    print_k_level(root->right, k - 1);
}

void print_all_level(node *root, int hgt)
{
    // cout << "level: " << k << endl;

    for (int i = 0; i <= hgt; i++)
    {
        print_k_level(root, i);
    }
}

void level_order(node *root)
{
    queue<node *> qu;
    qu.push(root);

    while (qu.size() >= 1)
    {
        node *front = qu.front();
        cout << front->data << ",";

        if (front->left)
        {
            qu.push(front->left);
        }
        if (front->right)
        {
            qu.push(front->right);
        }
        qu.pop();
    }
}

void level_order_space(node *root)
{
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);

    while (qu.size() > 1)
    {
        node *front = qu.front();
        if (front == NULL)
        {
            cout << endl;
            qu.push(NULL);
            qu.pop();
        }

        else
        {
            cout << front->data << ",";

            if (front->left)
            {
                qu.push(front->left);
            }
            if (front->right)
            {
                qu.push(front->right);
            }
            qu.pop();
        }
    }
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int own_diamter = height(root->left) + height(root->right) + 2;
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return (max_val(own_diamter, max_val(left_diameter, right_diameter)));
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair diameter_opt(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = -1;
        p.diameter = 0;
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair left = diameter_opt(root->left);
    Pair right = diameter_opt(root->right);
    p.height = max_val(left.height, right.height) + 1;
    int own_diameter = left.height + right.height + 2;
    p.diameter = max_val(own_diameter, max_val(left.diameter, right.height));

    return p;
}
int replace_with_desc_sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int temp = root->data;

    root->data = replace_with_desc_sum(root->left) + replace_with_desc_sum(root->right);
    return (temp + root->data);
}
int main()
{
    node *root = build_tree();
    //1 2 3 -1 -1 -1 4 5 -1 -1 6 7 -1 -1 -1
    //1 2 -1 -1 3 4 5 -1 -1 -1 6 -1 7 8 -1 -1 9 -1 -1

    //int hgt = height(root);
    //cout << hgt;

    // int k = 2;
    // print_k_level(root, k);
    //print_all_level(root, hgt);
    //level_order_space(root);

    // int dia = diameter(root);
    // cout << dia;

    // Pair ans = diameter_opt(root);
    // cout << ans.diameter;

    replace_with_desc_sum(root);
    level_order_space(root);
}