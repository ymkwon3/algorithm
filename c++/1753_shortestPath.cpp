#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K; // 정점, 간선, 시작점
int graph[20001];
vector<pair<int, int>> inputMap[20001];

void dijkstra()
{
    queue<int> que;
    que.push(K);
    while (!que.empty())
    {
        for (int i = 0; i < inputMap[que.front()].size(); i++)
        {
            if (graph[inputMap[que.front()][i].first] == 0 || graph[inputMap[que.front()][i].first] > graph[que.front()] + inputMap[que.front()][i].second)
            {
                graph[inputMap[que.front()][i].first] = graph[que.front()] + inputMap[que.front()][i].second;
                que.push(inputMap[que.front()][i].first);
            }
        }
        que.pop();
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