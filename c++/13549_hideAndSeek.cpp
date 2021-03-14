/*
deque를 활용하면 더 쉽게 풀 수 있다.
*/

#include <iostream>
#include <queue>
#define MAX 200001
using namespace std;

queue<pair<int, int>> q;
int n, k;

void bfs(int start)
{
    int visit[MAX];
    int position, time;

    for (int i = 0; i < MAX; i++)
        visit[i] = -1;

    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        position = q.front().first;
        time = q.front().second;
        q.pop();
        if (visit[position] == -1)
            visit[position] = time;
        else if (visit[position] > time)
            visit[position] = time;
        if (position * 2 <= k + 1)
        {
            if (visit[position * 2] == -1)
            {
                q.push(make_pair(position * 2, time));
            }
        }
        if (position + 1 <= k)
        {
            if (visit[position + 1] == -1)
            {
                q.push(make_pair(position + 1, time + 1));
            }
            else if (visit[position + 1] > time + 1)
            {
                q.push(make_pair(position + 1, time + 1));
            }
        }
        if (position - 1 >= 0)
        {
            if (visit[position - 1] == -1)
            {
                q.push(make_pair(position - 1, time + 1));
            }
            else if (visit[position - 1] > time + 1)
            {
                q.push(make_pair(position - 1, time + 1));
            }
        }
    }
    cout << visit[k] << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if (n == k)
        cout << 0 << "\n";
    else
        bfs(n);
    return 0;
}