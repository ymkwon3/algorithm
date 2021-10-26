#include <iostream>
#include <vector>
using namespace std;

int bigger(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = bigger(dp[i - 3] + v[i - 1] + v[i], bigger(dp[i - 2] + v[i], dp[i - 1]));
    }
    cout << dp[n] << "\n";
    return 0;
}