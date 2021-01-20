#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<long long> dp(MAX);
long long testcase, n;

void init()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i < MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        cout << dp[n] << "\n";
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