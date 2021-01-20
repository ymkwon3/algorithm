#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f;
vector<vector<bool>> visited;
int n, m, k, cnt;

int dfs(int startX, int startY)
{
    if (f[startY][startX] == 1 && !visited[startY][startX])
    {
        visited[startY][startX] = true;
        if (startX + 1 < m && f[startY][startX + 1] == 1 && !visited[startY][startX + 1])
        {
            dfs(startX + 1, startY);
        }
        if (startY + 1 < n && f[startY + 1][startX] == 1 && !visited[startY + 1][startX])
        {
            dfs(startX, startY + 1);
        }
        if (startX - 1 >= 0 && f[startY][startX - 1] == 1 && !visited[startY][startX - 1])
        {
            dfs(startX - 1, startY);
        }
        if (startY - 1 >= 0 && f[startY - 1][startX] == 1 && !visited[startY - 1][startX])
        {
            dfs(startX, startY - 1);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(j, i) == 1)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

void init()
{
    int testcase, x, y;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cnt = 0;
        cin >> m >> n >> k;
        for (int a = 0; a < n; a++)
        {
            vector<int> e(m);
            vector<bool> v(m, false);
            f.push_back(e);
            visited.push_back(v);
        }
        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            f[y][x] = 1;
        }
        solve();
        vector<vector<int>>().swap(f);
        vector<vector<bool>>().swap(visited);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}