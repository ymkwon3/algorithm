#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> q;
vector<pair<int, int>> position;
vector<bool> visit;
int t, n;

void clearQ(queue<int> &que)
{
    queue<int> empty;
    swap(que, empty);
}

void solve()
{
    while (!q.empty())
    {
        for (int i = 1; i < n + 2; i++)
        {
            if (abs(position[i].first - position[q.front()].first) + abs(position[i].second - position[q.front()].second) <= 1000 && !visit[i])
            {
                if (i == n + 1)
                {
                    clearQ(q);
                    cout << "happy\n";
                    return;
                }
                q.push(i);
                visit[i] = true;
            }
        }
        q.pop();
    }
    cout << "sad\n";
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n + 2; j++)
        {
            cin >> x >> y;
            position.push_back(make_pair(x, y));
            visit.push_back(false);
        }
        q.push(0);
        visit[0] = true;
        solve();
        clearQ(q);
        position.clear();
        visit.clear();
    }

    return 0;
}