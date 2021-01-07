#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> lans;
int k, n;
void init()
{
    long long a;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        lans.push_back(a);
    }
    sort(lans.begin(), lans.end());
}

void solve()
{
    long long ans = 0;
    long long mid, sum = 0;
    long long left = 1;
    long long right = lans[k - 1];
    while (left <= right)
    {
        sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < k; i++)
        {
            sum += lans[i] / mid;
        }
        if (sum >= n)
        {
            ans = mid;
            left = mid + 1;
        }
        else if (sum < n)
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