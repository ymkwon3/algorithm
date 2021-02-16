/*
어떠한 방식으로 풀어야 하는지에 대한 차이는 유사했지만
원래의 풀이 방식은 점화식 도출이 조금 부족했다.
*/

#include <iostream>

using namespace std;

int sticker[2][100001];
int dp[2][100001];
int testcase, n;

void solve()
{
    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[0][1] + dp[1][0];
    dp[1][1] = sticker[1][1] + dp[0][0];
    for (int i = 2; i < n; i++)
    {
        dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
                cin >> sticker[j][k];
        }
        solve();
    }

    return 0;
}