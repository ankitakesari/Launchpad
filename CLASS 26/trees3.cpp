#include <iostream>
#include <queue>
#include <bits/stdc++.h>
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

void level_order_nextline(node *root)
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

class Pair
{
public:
    int height;
    bool bal;
};

Pair is_balanced(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = -1;
        p.bal = true;
        return p;
    }

    Pair left = is_balanced(root->left);
    Pair right = is_balanced(root->right);

    p.height = max_val(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 && right.bal && left.bal)
    {
        p.bal = true;
    }

    else
    {
        p.bal = false;
    }
    return p;
}

void mirror(node *root)
{
    if (root == NULL)
    {
        return;
    }

    mirror(root->left);
    mirror(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void left_view(node *root)
{
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);
    cout << root->data << ",";

    while (qu.size() > 1)
    {
        node *front = qu.front();
        if (front == NULL)
        {
            //cout << endl;
            qu.pop();
            cout << qu.front()->data << ",";
            qu.push(NULL);
        }

        else
        {
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

void left_view2(node *root, int level, int &max_level)
{
    if (root == NULL)
    {
        return;
    }

    if (level > max_level)
    {
        max_level = level;
        cout << root->data << ",";
    }

    left_view2(root->left, level + 1, max_level);
    left_view2(root->right, level + 1, max_level);
}

node *build_balanced_tree(int *arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = build_balanced_tree(arr, start, mid - 1);
    root->right = build_balanced_tree(arr, mid + 1, end);

    return root;
}

int i = 0;

node *build_tree_preorder_inorder(int *pre, int *in, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    node *root = new node(pre[i]);

    int idx = -1;

    for (int k = start; k <= end; k++)
    {
        if (in[k] == pre[i])
        {
            idx = k;
            break;
        }
    }
    i++;

    root->left = build_tree_preorder_inorder(pre, in, start, idx - 1);
    root->right = build_tree_preorder_inorder(pre, in, idx + 1, end);

    return root;
}

int main()
{
    //node *root = build_tree();
    //1 2 3 -1 -1 -1 4 5 -1 -1 6 7 -1 -1 -1

    //     level_order_space(root);
    //     mirror(root);
    //     level_order_space(root);

    // int max_level = -1;
    // left_view2(root, 0, max_level);

    // Pair ans = is_balanced(root);
    // if (ans.bal)
    // {
    //     cout << "balanced";
    // }
    // else
    // {
    //     cout << "not balanced";
    // }

    // int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // node *root = build_balanced_tree(arr, 0, 8);

    // level_order_nextline(root);

    int pre[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int inorder[9] = {3, 2, 5, 4, 6, 1, 7, 8, 9};

    node *root = build_tree_preorder_inorder(pre, inorder, 0, 8);
    level_order_nextline(root);
}
