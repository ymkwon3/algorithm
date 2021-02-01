#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> town;
vector<vector<bool>> visit;
vector<int> cnt;
int n, c = 0;

void dfs(int a, int b)
{
    c++;
    visit[a][b] = true;
    if (b + 1 < n && town[a][b + 1] == 1 && !visit[a][b + 1])
    {
        dfs(a, b + 1);
    }
    if (a + 1 < n && town[a + 1][b] == 1 && !visit[a + 1][b])
    {
        dfs(a + 1, b);
    }
    if (b - 1 >= 0 && town[a][b - 1] == 1 && !visit[a][b - 1])
    {
        dfs(a, b - 1);
    }
    if (a - 1 >= 0 && town[a - 1][b] == 1 && !visit[a - 1][b])
    {
        dfs(a - 1, b);
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (town[i][j] == 1 && !visit[i][j])
            {
                dfs(i, j);
                cnt.push_back(c);
                c = 0;
            }
        }
    }
    sort(cnt.begin(), cnt.end());
    cout << cnt.size() << "\n";
    for (int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << "\n";
    }
}

int main(void)
{
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> e(n);
        vector<bool> ele(n, false);
        town.push_back(e);
        visit.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &town[i][j]);
        }
    }
    solve();
    return 0;
}