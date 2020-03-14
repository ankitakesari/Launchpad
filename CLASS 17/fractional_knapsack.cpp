#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<double, pair<int, int> > a, pair<double, pair<int, int> > b)
{
    return a.first > b.first;
}

int knapsack(int *wt, int *prices, int items, int weight)
{


    vector<pair<double, pair<int, int> > > v;


    for (int i = 0; i < items; i++)
    {

        pair<double, pair<int, int> > p;
        p = make_pair(prices[i] / (double)wt[i], make_pair(wt[i], prices[i]));
        v.push_back(p);
    }

    int total = 0;


    sort(v.begin(), v.end(), mycompare);


    int i = 0;
    while (weight > 0 && i < items)
    {

        if (v[i].second.first <= weight)
        {

            weight -= v[i].second.first;
            total += v[i].second.second;

        }

        else
        {
            total += v[i].first * weight;
            weight = 0;
        }
        i++;
    }

    return total;
}

int main()
{
    int items;
    cin >> items;

    int weight;
    cin >> weight;

    int wt[items];
    int price[items];



    for (int i = 0; i < items; i++)
    {
        cin >> wt[i];
    }


    for (int i = 0; i < items; i++)
    {
        cin >> price[i];
    }

    int total = knapsack(wt, price, items, weight);

    cout << "total: " << total;

    return 0;
}

