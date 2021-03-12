#include <iostream>
#include <queue>
#define MAX 200001
using namespace std;

queue<pair<int, int>> q;
bool visit[MAX];
int n, k, cnt, shortest = -1;

void bfs(int start)
{
    int top, s, pre = 0;
    q.push(make_pair(start, 0));
    visit[start] = true;
    while (!q.empty())
    {
        top = q.front().first;
        s = q.front().second;
        if (pre != 0 && pre < s)
            break;
        q.pop();
        visit[top] = true;
        if (top == k)
        {
            shortest = s;
            cnt++;
            pre = s;
            continue;
        }

        if (top - 1 >= 0 && !visit[top - 1])
            q.push(make_pair(top - 1, s + 1));
        if (top * 2 < MAX && !visit[top * 2])
            q.push(make_pair(top * 2, s + 1));
        if (top + 1 <= k && !visit[top + 1])
            q.push(make_pair(top + 1, s + 1));
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n"
             << 1 << "\n";
    }
    else
    {
        bfs(n);
        cout << shortest << "\n"
             << cnt << "\n";
    }
    return 0;
}