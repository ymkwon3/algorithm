#include <iostream>
#include <vector>

using namespace std;
vector<vector<short>> graph(100, vector<short>(100));
vector<bool> visit(100);
short n;

void dfs(short row, short col)
{
    for (short k = 0; k < n; k++)
    {
        if (graph[col][k] == 1 && !visit[k])
        {
            graph[row][k] = 1;
            visit[k] = true;
            if (row != k)
                dfs(row, k);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                dfs(i, j);
                visit.assign(n, false);
            }
        }
    }

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    return 0;
}