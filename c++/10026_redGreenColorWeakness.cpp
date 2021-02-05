/*

풀이 : 적록색약일 경우, 정상일 경우. 두개의 dfs를 만들어 해결
후기 : 아직 dfs bfs를 자연스럽게 활용하지 못하는 것 같다.
testcase:

3
RRG
RGG
GGB

ans: 3 2

5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

ans: 4 3
*/

#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> color;
vector<vector<bool>> visit;

int n;

bool cmp(char a, char b)
{
    if ((a == 'R' || a == 'G') && (b == 'R' || b == 'G'))
        return 1;
    else if (a == 'B' && b == 'B')
        return 1;
    else
        return 0;
}

void weakness_dfs(int i, int j)
{
    visit[i][j] = true;
    if (j + 1 < n && !visit[i][j + 1] && cmp(color[i][j], color[i][j + 1]))
        weakness_dfs(i, j + 1);
    if (i + 1 < n && !visit[i + 1][j] && cmp(color[i][j], color[i + 1][j]))
        weakness_dfs(i + 1, j);
    if (j - 1 >= 0 && !visit[i][j - 1] && cmp(color[i][j], color[i][j - 1]))
        weakness_dfs(i, j - 1);
    if (i - 1 >= 0 && !visit[i - 1][j] && cmp(color[i][j], color[i - 1][j]))
        weakness_dfs(i - 1, j);
}

int weakness()
{
    visit.assign(n, vector<bool>(n));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                weakness_dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void normal_dfs(int i, int j)
{
    visit[i][j] = true;
    if (j + 1 < n && !visit[i][j + 1] && color[i][j] == color[i][j + 1])
        normal_dfs(i, j + 1);
    if (i + 1 < n && !visit[i + 1][j] && color[i][j] == color[i + 1][j])
        normal_dfs(i + 1, j);
    if (j - 1 >= 0 && !visit[i][j - 1] && color[i][j] == color[i][j - 1])
        normal_dfs(i, j - 1);
    if (i - 1 >= 0 && !visit[i - 1][j] && color[i][j] == color[i - 1][j])
        normal_dfs(i - 1, j);
}

int normal()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                normal_dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<char> element;
        vector<bool> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            element.push_back(c);
        }
        color.push_back(element);
        visit.push_back(v);
    }

    cout << normal() << " ";
    cout << weakness() << "\n";
    return 0;
}