
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> merge_k_sorted_arrays(vector<vector<int>> v)
{
    priority_queue<node, vector<node>, greater<node>> pq;

    vector<int> result;
    int k = v.size();
    int i = 0;
    while (i < k)
    {
        node ele = make_pair(v[i][0], make_pair(i, 0));
        pq.push(ele);
        i++;
    }

    while (!pq.empty())
    {
        node top_ele = pq.top();
        result.push_back(top_ele.first);

        pq.pop();

        int arr_number = top_ele.second.first;
        int index_number = top_ele.second.second;

        if (index_number + 1 < v[arr_number].size())
        {
            node ele = make_pair(v[arr_number][index_number + 1], make_pair(arr_number, index_number + 1));
            pq.push(ele);
        }
    }

    return result;
}
int main()
{

    int k;
    cin >> k;

    int n;
    cin >> n;

    // vector < vector<int> > v {{1,5,8,9,10},
    // 						{11,24,36,58, 223},
    // 						{2,4,6}};

    vector<vector<int>> v;

    int i = 0;
    while (i < k)
    {
        vector<int> vect_temp(n);
        for (int j = 0; j < n; j++)
        {
            cin >> vect_temp[j];
        }
        v.push_back(vect_temp);
        i++;
    }

    vector<int> result = merge_k_sorted_arrays(v);

    for (int x = 0; x < result.size(); x++)
    {
        cout << result[x] << " ";
    }
}
