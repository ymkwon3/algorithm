#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1002][1002];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;

    cin >> a >> b;
    for (int i = 1; i <= b.size(); i++)
    {
        for (int j = 1; j <= a.size(); j++)
        {
            if (b[i - 1] == a[j - 1])
                dp[i][j] += dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[b.size()][a.size()] << "\n";
    return 0;
}