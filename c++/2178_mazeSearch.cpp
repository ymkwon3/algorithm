#include <iostream>
#include <vector>
#include <queue>

using namespace std; // 힝 dfs 시간초과...bfs로 풀자...
int n, m, e = 99999999, path = 0;
vector<vector<int>> maze;
vector<vector<int>> graph;
vector<bool> visit;
queue<pair<int, int>> q;

void toGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i * n + j + 1] = true;
            if (maze[i][j] == 1)
            {
                if (j + 1 < m && maze[i][j + 1] == 1 && visit[i * n + j + 2] == false)
                {
                    graph[i * m + j + 1].push_back(i * m + j + 2);
                    graph[i * m + j + 2].push_back(i * m + j + 1);
                }
                if (i + 1 < n && maze[i + 1][j] == 1 && visit[(i + 1) * n + j + 1] == false)
                {
                    graph[i * m + j + 1].push_back((i + 1) * m + j + 1);
                    graph[(i + 1) * m + j + 1].push_back(i * m + j + 1);
                }
                if (j - 1 >= 0 && maze[i][j - 1] == 1 && visit[i * m + j] == false)
                {
                    graph[i * m + j + 1].push_back(i * m + j);
                    graph[i * m + j].push_back(i * m + j + 1);
                }
                if (i - 1 >= 0 && maze[i - 1][j] == 1 && visit[(i - 1) * m + j + 1] == false)
                {
                    graph[i * m + j + 1].push_back((i - 1) * m + j + 1);
                    graph[(i - 1) * m + j + 1].push_back(i * m + j + 1);
                }
            }
        }
    }
    visit.assign(n * m + 1, false);
}

// void dfs(int start)
// {
//     path++;
//     if (start == n * m)
//     {
//         if (path < e)
//             e = path;
//         return;
//     }
//     visit[start] = true;
//     for (int i = 0; i < graph[start].size(); i++)
//     {
//         if (visit[graph[start][i]] == false)
//         {
//             dfs(graph[start][i]);
//             path--;
//         }
//     }
//     visit[start] = false;
// }

void bfs()
{
    q.push(make_pair(1, 1));
    visit[1] = true;
    while (!q.empty())
    {
        for (int i = 0; i < graph[q.front().first].size(); i++)
        {
            if (graph[q.front().first][i] == n * m)
            {
                cout << q.front().second + 1 << "\n";
                return;
            }
            if (visit[graph[q.front().first][i]] == false)
            {
                q.push(make_pair(graph[q.front().first][i], q.front().second + 1));
                visit[graph[q.front().first][i]] = true;
            }
        }
        q.pop();
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> e(m);
        maze.push_back(e);
    }
    for (int i = 0; i <= n * m; i++)
    {
        vector<int> e;
        graph.push_back(e);
        visit.push_back(false);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &maze[i][j]);
    toGraph();
    bfs();
    // cout << e << "\n";
    return 0;
}