/*
처음에는 모든 테크로미노의 대칭 회전 경우의 수를 감안해서 하나 하나 브루트포스로 돌리려 했지만,
그렇게 되면 코드가 너무 지저분해 질것 같아서 찾아보니 ㅗ를 제외한 다른 모양들은 4번의 dfs를 거친
모양과 같았다.
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> area;
vector<vector<bool>> visit;
int maxi = 0;
int sx[4] = {1, 0, -1, 0};
int sy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt, int sum)
{
    if (cnt == 4)
    {
        maxi = maxi < sum ? sum : maxi;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int cx = x + sx[k];
        int cy = y + sy[k];
        if (cx < 0 || cy < 0 || cx >= m || cy >= n)
            continue;
        if (!visit[cy][cx])
        {
            visit[cy][cx] = true;
            dfs(cx, cy, cnt + 1, sum + area[cy][cx]);
            visit[cy][cx] = false;
        }
    }
}

void remainder(int x, int y)
{
    int sum = 0;
    if (x + 1 < m && y - 1 >= 0 && x - 1 >= 0)
    {
        sum = area[y][x] + area[y - 1][x] + area[y][x + 1] + area[y][x - 1];
        maxi = maxi < sum ? sum : maxi;
    }
    if (x + 1 < m && y - 1 >= 0 && y + 1 < n)
    {
        sum = area[y][x] + area[y - 1][x] + area[y][x + 1] + area[y + 1][x];
        maxi = maxi < sum ? sum : maxi;
    }
    if (x - 1 >= 0 && y + 1 < n && x + 1 < m)
    {
        sum = area[y][x] + area[y + 1][x] + area[y][x - 1] + area[y][x + 1];
        maxi = maxi < sum ? sum : maxi;
    }
    if (y + 1 < n && y - 1 >= 0 && x - 1 >= 0)
    {
        sum = area[y][x] + area[y + 1][x] + area[y - 1][x] + area[y][x - 1];
        maxi = maxi < sum ? sum : maxi;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        area.push_back(vector<int>(m));
        visit.push_back(vector<bool>(m));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> area[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = true;
            dfs(j, i, 1, area[i][j]);
            visit[i][j] = false;

            remainder(j, i);
        }
    }
    cout << maxi << "\n";
    return 0;
}