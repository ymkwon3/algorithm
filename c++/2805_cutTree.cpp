#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> trees;
int n, m;

void init()
{
    long long a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        trees.push_back(a);
    }
    sort(trees.begin(), trees.end());
}

long long cutting(long long h)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] - h > 0)
            sum += trees[i] - h;
    }
    return sum;
}

void solve()
{
    long long ans;
    long long left = 0;
    long long right = trees[n - 1];
    long long mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (cutting(mid) >= m)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
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