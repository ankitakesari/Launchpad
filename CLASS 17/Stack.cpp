#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int x)
    {
        v.push_back(x);
    }

    void pop()
    {
        v.pop_back();
    }

    bool is_empty()
    {
        return (v.size() == 0);
    }

    int top()
    {
        if (is_empty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }

        return (v[v.size() - 1]);
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    return 0;
}