#include <iostream>
#include <vector>
#define MAX 5;
using namespace std;

vector<int> dp(50001);
int n;

void init()
{
    cin >> n;
}

void solve()
{
    int minn;
    int sub;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        minn = MAX;
        for (int j = 1; j * j <= i; j++)
        {
            sub = i - j * j;
            minn = min(minn, dp[sub]);
        }
        dp[i] = minn + 1;
    }
    cout << dp[n] << "\n";
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