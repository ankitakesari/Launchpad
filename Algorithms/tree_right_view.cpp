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

void right_view(node *root)
{
    queue<node *> qu;

    qu.push(root);
    qu.push(NULL);
    cout << root->data;

    while (qu.size() > 1)
    {
        node *front = qu.front();

        if (front == NULL)
        {
            cout << " ";
            qu.pop();
            cout << qu.front()->data;
            qu.push(NULL);
        }

        else
        {
            if (front->right)
            {
                qu.push(front->right);
            }
            if (front->left)
            {
                qu.push(front->left);
            }

            qu.pop();
        }
    }
}

int main()
{

    queue<node *> q;

    node *root = NULL;

    int input;
    cin >> input;

    if (input != -1)
    {
        root = new node(input);
        q.push(root);

        while (q.size() > 0)
        {
            node *front = q.front();

            cin >> input;

            if (input != -1)
            {
                front->left = new node(input);
                q.push(front->left);
            }

            cin >> input;

            if (input != -1)
            {
                front->right = new node(input);
                q.push(front->right);
            }

            q.pop();
        }
    }

    // print(root);

    //1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1

    right_view(root);
}