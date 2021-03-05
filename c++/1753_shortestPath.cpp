#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K; // 정점, 간선, 시작점
int graph[20001];
vector<pair<int, int>> inputMap[20001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, K));
    graph[K] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < inputMap[cur].size(); i++)
        {
            int next = inputMap[cur][i].first;
            int nCost = inputMap[cur][i].second;
            if (graph[next] == 0 || graph[next] > cost + nCost)
            {
                graph[next] = cost + nCost;
                pq.push(make_pair(-graph[next], next));
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        inputMap[u].push_back(make_pair(v, w));
    }
    dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if (i == K)
            cout << "0\n";
        else if (graph[i] == 0)
            cout << "INF\n";
        else
            cout << graph[i] << "\n";
    }
    return 0;
}