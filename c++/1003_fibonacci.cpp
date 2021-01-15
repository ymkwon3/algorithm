/*
Find the number of outputs 0 and 1 in the Fibonacci sequence
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dp(41);
int testcase, n;

void init()
{
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    for (int i = 2; i <= 40; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}