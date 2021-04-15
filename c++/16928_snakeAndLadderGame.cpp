#include <iostream>
#include <queue>
using namespace std;

int graph[101];
int cnt_ladder, cnt_snake;
bool visit[101];
queue<pair<int, int>> q;

void bfs()
{
    for (int i = 2; i < 8; i++)
    {
        if (graph[i] == 0 && !visit[i])
        {
            q.push({i, 1});
            visit[i] = true;
        }
        else if (!visit[i])
        {
            q.push({graph[i], 1});
            visit[graph[i]] = true;
        }
    }
    while (!q.empty())
    {
        int node = q.front().first;
        int cnt = q.front().second;
        if (node == 100)
        {
            cout << cnt << "\n";
            break;
        }
        q.pop();
        for (int i = node + 1; i < node + 7; i++)
        {
            if (i > 100)
                break;
            if (graph[i] == 0 && !visit[i])
            {
                q.push({i, cnt + 1});
                visit[i] = true;
            }
            else if (!visit[i])
            {
                q.push({graph[i], cnt + 1});
                visit[graph[i]] = true;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int input_a, input_b;

    cin >> cnt_ladder >> cnt_snake;
    for (int i = 0; i < cnt_ladder; i++)
    {
        cin >> input_a >> input_b;
        graph[input_a] = input_b;
    }

    for (int i = 0; i < cnt_snake; i++)
    {
        cin >> input_a >> input_b;
        graph[input_a] = input_b;
    }

    bfs();

    return 0;
}