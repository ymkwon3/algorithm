#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

vector<int> items(101);
vector<int> tmp(101, INF);
vector<pair<int, int>> roads[101];

int dijkstra(int start, int n, int m)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().second;
        int cur = pq.top().first;
        pq.pop();

        if (dist[cur] < cost)
            continue;

        for (int i = 0; i < roads[cur].size(); i++)
        {
            int next = roads[cur][i].first;
            int nCost = roads[cur][i].second + cost;

            if (dist[next] > nCost)
            {
                dist[next] = nCost;
                pq.push({next, -nCost});
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= dist.size(); i++)
    {
        if (dist[i] <= m)
            result += items[i];
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
        tmp = dijkstra(i, n, m);
        answer = tmp > answer ? tmp : answer;
    }

    cout << answer << "\n";
    return 0;
}