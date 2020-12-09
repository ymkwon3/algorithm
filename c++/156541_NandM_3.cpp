#include <iostream>

using namespace std;
const int MAX = 8;
int arr[MAX];
int visited[MAX];
int n, m;

void init()
{
    cin >> n >> m;
}

void solve(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[cnt] = i;
        solve(cnt + 1);
    }
}

int main(void)
{
    init();
    solve(0);
    return 0;
}