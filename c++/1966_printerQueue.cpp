#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve(int n, int m);

void init()
{
    int testcase, n, m;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n >> m;
        solve(n, m);
    }
}

int maximum(queue<int> q)
{
    int max = 0;
    while (!q.empty())
    {
        if (max < q.front())
            max = q.front();
        q.pop();
    }
    return max;
}

void solve(int n, int m)
{
    int a;
    int index = m;
    int cnt = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }
    while (!q.empty())
    {
        if (q.front() != maximum(q))
        {
            q.push(q.front());
            q.pop();
            if (index == 0)
                index += q.size() - 1;
            else
                index--;
        }
        else
        {
            q.pop();
            cnt++;
            if (index == 0)
            {
                cout << cnt << "\n";
                break;
            }
            else
                index--;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    return 0;
}