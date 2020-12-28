#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
}

void solve()
{
    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << "\n";
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