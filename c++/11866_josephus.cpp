#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, k;

void init()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
}

void solve()
{
    cout << "<";
    while (!q.empty())
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (!q.empty())
        {
            cout << ", ";
        }
    }
    cout << ">";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}