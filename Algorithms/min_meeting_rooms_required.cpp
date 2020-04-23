#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
void rooms_needed(vector<vector<int>> meetings)
{
    priority_queue<p, vector<p>, greater<p>> minStartTime;
    priority_queue<p, vector<p>, greater<p>> minEndTime;

    int i = 0;
    while (i < meetings.size())
    {
        p p1 = make_pair(meetings[i][0], meetings[i][1]);
        minStartTime.push(p1);
        i++;
    }

    int required_rooms = 0;

    if (!minStartTime.empty())
    {
        p p2 = make_pair(minStartTime.top().second, minStartTime.top().first);
        minEndTime.push(p2);
        minStartTime.pop();
        required_rooms++;
    }

    while (!minStartTime.empty())
    {
        p curr_meeting = minStartTime.top();
        minStartTime.pop();

        if (curr_meeting.first < minEndTime.top().first)
        {
            p p3 = make_pair(curr_meeting.second, curr_meeting.first);
            minEndTime.push(p3);
            int heap_size = minEndTime.size();
            required_rooms = max(required_rooms, heap_size);
        }

        else
        {
            while (!minEndTime.empty() && !minStartTime.empty() && curr_meeting.first >= minEndTime.top().first)
            {
                minEndTime.pop();
            }
            minEndTime.push(make_pair(curr_meeting.second, curr_meeting.first));
        }
    }

    cout << required_rooms;
}

int main()
{
    vector<vector<int>> meetings{{0, 5}, {6, 9}, {9, 23}};

    rooms_needed(meetings);
    return 0;
}
