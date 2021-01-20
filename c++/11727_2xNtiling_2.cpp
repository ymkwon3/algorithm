#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> dp(MAX);
int n;

void init()
{
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < MAX; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
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