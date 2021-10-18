#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

int bfs(int a, int b, vector<vector<int>> v, int n)
{
    int aV = 0, bV = 0;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < v.size(); i++)
    {
        tree[v[i][0]].push_back(v[i][1]);
        tree[v[i][1]].push_back(v[i][0]);
    }
    queue<int> q;
    vector<bool> visit(n + 1);
    q.push(a);

    while (!q.empty())
    {
        int cur = q.front();
        visit[cur] = true;
        q.pop();
        aV++;
        for (int i = 0; i < tree[cur].size(); i++)
        {
            if (!visit[tree[cur][i]])
            {
                q.push(tree[cur][i]);
            }
        }
    }

    for (int i = 0; i < visit.size(); i++)
        visit[i] = false;
    int bEnd = tree[b].size() == 0 ? 0 : tree[b][0];
    q.push(b);
    while (!q.empty())
    {
        int cur = q.front();
        visit[cur] = true;
        q.pop();
        bV++;
        for (int i = 0; i < tree[cur].size(); i++)
        {
            if (!visit[tree[cur][i]])
            {
                q.push(tree[cur][i]);
            }
        }
    }
    return aV > bV ? aV - bV : bV - aV;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 99999999, result;
    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> v = wires;
        v.erase(v.begin() + i);
        result = bfs(wires[i][0], wires[i][1], v, n);
        if (answer > result)
            answer = result;
    }

    cout << answer << "\n";
    return answer;
}
int main()
{
    solution(7, {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}});
    return 0;
}