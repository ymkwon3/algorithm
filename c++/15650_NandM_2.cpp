/*
오름차순
*/
#include <iostream>

using namespace std;
const int MAX = 9;
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
        for (int i = 0, pre = 0; i < m; i++)
        {
            if (pre > arr[i])
                return;
            pre = arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    init();
    solve(0);
    return 0;
}