#include <iostream>
#include <vector>
#define MAX 301

using namespace std;

vector<int> dp(MAX);
vector<int> s(MAX);
int n;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
}

void solve()
{
    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    dp[3] = max(s[1] + s[3], s[2] + s[3]);
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
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