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

int min_val(int a, int b)
{
    if (a <= b)
    {
        return a;
    }

    else
    {
        return b;
    }
}

//dry run for 1 2 3 -1 -1 -1 4 5 -1 -1 6 7 -1 -1 -1 to find flaw
// int min_depth(node *root)
// {
//     cout << "a" << endl;
//     if (root == NULL)
//     {
//         return -1;
//     }

//     int left = min_depth(root->left);
//     int right = min_depth(root->right);

//     return (min_val(left, right) + 1);
// }

int min_depth(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int left = min_depth(root->left);
    int right = min_depth(root->right);

    return (min_val(left, right) + 1);
}

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

bool trees_identical(node *root1, node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 != NULL)
    {
        bool left = trees_identical(root1->left, root2->left);
        bool right = trees_identical(root1->right, root2->right);
        if (root1->data == root2->data && left && right)
        {
            return true;
        }
    }

    return false;
}

bool trees_structure_identical(node *root1, node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 != NULL)
    {
        bool left = trees_identical(root1->left, root2->left);
        bool right = trees_identical(root1->right, root2->right);
        if (left && right)
        {
            return true;
        }
    }

    return false;
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

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    node *left = lca(root->left, a, b);
    node *right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (right == NULL)
    {
        return left;
    }

    else
    {
        return right;
    }
}

void nodes_at_distance_k_in_subtree(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    nodes_at_distance_k_in_subtree(root->left, k - 1);
    nodes_at_distance_k_in_subtree(root->right, k - 1);
}

int nodes_at_distance_k(node *root, int target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == target)
    {
        nodes_at_distance_k_in_subtree(root, k);
        return 0;
    }

    int dLeft = nodes_at_distance_k(root->left, target, k);
    if (dLeft != -1)
    {
        if (dLeft + 1 == k)
        {
            cout << root->data << ",";
        }

        else
        {
            nodes_at_distance_k_in_subtree(root->right, k - dLeft - 2);
        }

        return (dLeft + 1);
    }

    int dRight = nodes_at_distance_k(root->right, target, k);
    if (dRight != -1)
    {
        if (dRight + 1 == k)
        {
            cout << root->data << ",";
        }

        else
        {
            nodes_at_distance_k_in_subtree(root->left, k - dRight - 2);
        }

        return (dRight + 1);
    }

    return -1;
}

int main()
{
    node *root = build_tree();

    //node *root2 = build_tree();

    //1 2 3 -1 -1 -1 4 5 -1 -1 6 7 -1 -1 -1
    //1 2 -1 -1 3 4 5 -1 -1 -1 6 -1 7 8 -1 -1 9 -1 -1

    // bool result = trees_identical(root, root2);

    // if (result)
    // {
    //     cout << "identical";
    // }

    // else
    // {
    //     cout << "unidentical";
    // }

    // bool result2 = trees_structure_identical(root, root2);

    // if (result2)
    // {
    //     cout << "identical";
    // }

    // else
    // {
    //     cout << "unidentical";
    // }

    // int minn = min_depth(root);
    // cout << minn;

    // node *ans = lca(root, 6, 7);
    // cout << ans->data;

    nodes_at_distance_k(root, 4, 2);
}