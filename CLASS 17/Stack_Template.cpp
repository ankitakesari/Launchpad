#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
    vector<T> v;

public:
    void push(T x)
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

    T top()
    {
        if (is_empty())
        {
            cout << "stack is empty" << endl;
            return NULL;
        }

        return (v[v.size() - 1]);
    }
};

int main()
{
    Stack<int> st;

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