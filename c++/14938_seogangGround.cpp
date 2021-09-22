#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> items(101);
vector<vector<pair<int, int>>> roads(101);

int bfs(int start, int m)
{
    vector<bool> visit(101);
    queue<pair<int, int>> q;
    q.push({start, 0});
    int result = 0;
    while (!q.empty())
    {
        int startNode = q.front().first;
        visit[startNode] = true;
        int cost = q.front().second;
        result += items[startNode];
        q.pop();
        for (auto a : roads[startNode])
        {
            cout << a.first << " " << a.second << " " << cost << " " << visit[a.first] << "\n";
            if (a.second + cost <= m && !visit[a.first])
            {
                q.push({a.first, a.second + cost});
            }
        }
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    int input1, input2, input3;
    int answer = 0, tmp;

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        cin >> input1;
        items[i] = input1;
    }

    for (int i = 0; i < r; i++)
    {
        cin >> input1 >> input2 >> input3;

        roads[input1].push_back({input2, input3});
        roads[input2].push_back({input1, input3});
    }

    for (int i = 1; i <= n; i++)
    {
        tmp = bfs(i, m);
        answer = tmp > answer ? tmp : answer;
    }
    cout << answer << "\n";
    return 0;
}