#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;
vector<int> input;
int arr[MAX];
int visited[MAX];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 0, a = 0; i < n; i++)
    {
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
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
    for (int i = 0; i < n; i++)
    {
        arr[cnt] = input[i];
        solve(cnt + 1);
    }
}

int main(void)
{
    init();
    solve(0);
    return 0;
}