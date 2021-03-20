/*

1 -> v1 -> v2 -> n
1 -> v2 -> v1 -> n

*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
using namespace std;

vector<pair<int, int>> v[MAX];
int node[MAX];
int n, e;
int v1, v2;
bool connect = true;

int min(int a, int b)
{
    return a > b ? b : a;
}

void reset()
{
    for (int i = 0; i < MAX; i++)
        node[i] = 0;
}

int dijkstra(int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    else
    {
        reset();
        priority_queue<pair<int, int>> pq; // <node, cost>
        pq.push({start, 0});
        while (!pq.empty())
        {
            int cur_node = pq.top().first;
            int cur_cost = -pq.top().second;
            pq.pop();
            for (int i = 0; i < v[cur_node].size(); i++)
            {
                int next_node = v[cur_node][i].first;
                int next_cost = v[cur_node][i].second;
                if (node[next_node] == 0 || node[next_node] > cur_cost + next_cost)
                {
                    node[next_node] = cur_cost + next_cost;
                    pq.push({next_node, -node[next_node]});
                }
            }
        }
        if (node[end] == 0)
            connect = false;

        return node[end];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int d1, d2, d3;
    int D1, D2, D3;
    d1 = dijkstra(1, v1);
    d2 = dijkstra(v1, v2);
    d3 = dijkstra(v2, n);
    D1 = dijkstra(1, v2);
    D2 = dijkstra(v2, v1);
    D3 = dijkstra(v1, n);
    if (!connect)
        cout << -1 << "\n";
    else
        cout << min(d1 + d2 + d3, D1 + D2 + D3) << "\n";
    return 0;
}