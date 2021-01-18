#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

vector<int> dp(MAX);
int n;

void init()
{
    int mini;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < MAX; i++)
    {
        if (i % 6 == 0)
        {
            mini = min(dp[i / 2], dp[i / 3]);
            mini = min(dp[i - 1], mini);
        }
        else if (i % 2 == 0)
        {
            mini = min(dp[i - 1], dp[i / 2]);
        }
        else if (i % 3 == 0)
        {
            mini = min(dp[i - 1], dp[i / 3]);
        }
        else
        {
            mini = dp[i - 1];
        }
        dp[i] = mini + 1;
    }
    cin >> n;
    cout << dp[n] << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}