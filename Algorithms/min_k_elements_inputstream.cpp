//min k elements till -1 is encountered in input stream
//input stream is stopped when -1000 is encountered
#include <bits/stdc++.h>
using namespace std;

void print_min_heap(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void top_k_elements(int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    int curr_size = 0;

    while (n != -1000)
    {
        if (n != -1)
        {
            if (curr_size < k)
            {
                pq.push(n);
                curr_size++;
            }

            else if (n > pq.top())
            {
                pq.pop();
                pq.push(n);
            }
        }

        else
        {
            print_min_heap(pq);
        }
        cin >> n;
    }
}
int main()
{
    int k;
    cin >> k;

    top_k_elements(k);
    return 0;
}
