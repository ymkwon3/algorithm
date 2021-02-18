#include <iostream>

using namespace std;

int street[1000][3];
int dp[1000][3];
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> street[0][0] >> street[0][1] >> street[0][2];
    dp[0][0] = street[0][0];
    dp[0][1] = street[0][1];
    dp[0][2] = street[0][2];
    for (int i = 1; i < n; i++)
    {
        cin >> street[i][0] >> street[i][1] >> street[i][2];
        dp[i][0] = (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]) + street[i][0];
        dp[i][1] = (dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2]) + street[i][1];
        dp[i][2] = (dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]) + street[i][2];
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
    return 0;
}