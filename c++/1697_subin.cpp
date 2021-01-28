#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
vector<bool> v(100001, false);
int n, k;

void bfs()
{

    if (n - 1 >= 0)
    {
        q.push(make_pair(n - 1, 1));
        v[n - 1] = true;
    }
    if (n + 1 < 100001)
    {
        q.push(make_pair(n + 1, 1));
        v[n + 1] = true;
    }
    if (n * 2 < 100001)
    {
        q.push(make_pair(n * 2, 1));
        v[n * 2] = true;
    }

    while (!q.empty())
    {
        if (q.front().first - 1 >= 0 && !v[q.front().first - 1])
        {
            q.push(make_pair(q.front().first - 1, q.front().second + 1));
            v[q.front().first - 1] = true;
        }

        if (q.front().first + 1 < 100001 && !v[q.front().first + 1])
        {
            q.push(make_pair(q.front().first + 1, q.front().second + 1));
            v[q.front().first + 1] = true;
        }
        if (q.front().first * 2 < 100001 && !v[q.front().first * 2])
        {
            q.push(make_pair(q.front().first * 2, q.front().second + 1));
            v[q.front().first * 2] = true;
        }
        if (q.front().first == k)
        {
            cout << q.front().second << "\n";
            break;
        }
        q.pop();
    }
}

void solve()
{
    if (n == k)
        cout << 0 << "\n";
    else if (n < k)
        bfs();
    else if (n > k)
        cout << n - k << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    solve();
    return 0;
}