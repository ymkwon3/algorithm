#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int n, m;

void init()
{
    vector<int> element;
    int a, b;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        graph.push_back(element);
        visited.push_back(false);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void solve()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[i] && !visited[graph[i][j]])
            {
                visited[i] = true;
                cnt++;
            }
            visited[graph[i][j]] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();
    return 0;
}