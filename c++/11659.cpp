#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j;

    cin >> n >> m;
    int input;
    dp.push_back(0);
    for (int a = 1; a <= n; a++)
    {
        cin >> input;
        dp.push_back(dp[a - 1] + input);
    }

    for (int a = 0; a < m; a++)
    {
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }

    return 0;
}