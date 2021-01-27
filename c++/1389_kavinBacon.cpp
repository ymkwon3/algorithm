#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<vector<int>> relation(MAX);
vector<bool> visit(MAX, false);
vector<int> dep(MAX);
int n, m, cnt = 0, depth = 0;

void init()
{
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
}

void dfs(int start)
{
    depth++;
    visit[start] = true;
    for (int i = 0; i < relation[start].size(); i++)
    {
        if (!visit[relation[start][i]])
        {
            visit[relation[start][i]] = true;
            dep[relation[start][i]] = depth;
            cnt += depth;
        }
    }
    for (int i = 0; i < relation[start].size(); i++)
    {
        if (dep[relation[start][i]] == 0 || dep[relation[start][i]] == depth)
        {
            dfs(relation[start][i]);
        }
    }
    depth--;
}

int main(void)
{
    int index, mini = MAX;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        if (mini > cnt)
        {
            mini = cnt;
            index = i;
        }
        visit.assign(n, false);
        dep.assign(n, 0);
        cnt = 0;
    }
    cout << index << "\n";
    return 0;
}