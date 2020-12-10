#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 9;
vector<int> input;
int arr[MAX];
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
    for (int i = 0, pre = 0; i < n; i++)
    {
        if (pre == input[i])
            continue;

        arr[cnt] = input[i];
        solve(cnt + 1);
        pre = input[i];
    }
}

int main(void)
{
    init();
    solve(0);
    return 0;
}