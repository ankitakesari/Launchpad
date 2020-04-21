#include <iostream>
#include <queue>
#include <vector>
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

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int minn = 0;
int maxx = 0;

void findMinMax(node *root, int hd)
{
    // Base case
    if (root == NULL)
        return;

    // Update min and max
    if (hd < minn)
        minn = hd;
    else if (hd > maxx)
        maxx = hd;

    // Recur for left and right subtrees
    findMinMax(root->left, hd - 1);
    findMinMax(root->right, hd + 1);
}

void vertical_order(node *root, int pos, int level)
{

    if (root == NULL)
    {
        return;
    }
    if (pos == level)
    {
        cout << root->data << " ";
        //do not add return;
    }

    vertical_order(root->left, pos - 1, level);
    vertical_order(root->right, pos + 1, level);
}

int main()
{
    // int n;
    // cin >> n;
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

    findMinMax(root, 0);
    cout << "min: " << minn << endl;
    cout << "max: " << maxx << endl;

    for (int line_no = minn; line_no <= maxx; line_no++)
    {

        vertical_order(root, 0, line_no);
        cout << endl;
    }
}