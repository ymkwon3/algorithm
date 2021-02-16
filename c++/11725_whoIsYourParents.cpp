#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> m;
int visit[100001];
int n;

void dfs(int index)
{
    for (int i = 0; i < m[index].size(); i++)
    {
        if (visit[m[index][i]] == 0)
        {
            visit[m[index][i]] = index;
            dfs(m[index][i]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int a, b;
    visit[1] = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i < n + 1; i++)
    {
        cout << visit[i] << "\n";
    }

    return 0;
}