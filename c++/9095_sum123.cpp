#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(11);
int n;

void init()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    int index;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> index;
        cout << dp[index] << "\n";
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