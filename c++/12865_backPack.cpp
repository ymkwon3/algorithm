#include <iostream>
using namespace std;

int w[101];
int v[101];
int dp[101][100001];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}