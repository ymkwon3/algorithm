#include <iostream>
#include <vector>
#define INFINITY 2000000000
using namespace std;

vector<pair<int, int>> v[501];
int graph[501];

void bellmanFord()
{
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(graph, 501, INFINITY);
    int tc, n, m, w;
    int s, e, t;

    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n >> m >> w;
        for (int j = 0; j < m; j++)
        {
            cin >> s >> e >> t;
            v[s].push_back({e, t});
            v[e].push_back({s, t});
        }
        for (int j = 0; j < w; j++)
        {
            v[s].push_back({e, -t});
        }
    }

    return 0;
}