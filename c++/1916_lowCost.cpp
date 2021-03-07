#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 200000000;

int n, m;
int s, e;
int graph[1001];
vector<pair<int, int>> info[1001];

void dijkstra()
{
    for (int i = 0; i < 1001; i++)
        graph[i] = INF;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    graph[s] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < info[cur].size(); i++)
        {
            int nCost = info[cur][i].second;
            int next = info[cur][i].first;
            if (graph[next] > nCost + cost)
            {
                graph[next] = nCost + cost;
                pq.push(make_pair(-graph[next], next));
            }
        }
    }

    cout << graph[e] << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        info[a].push_back(make_pair(b, c));
    }
    cin >> s >> e;
    dijkstra();
    return 0;
}