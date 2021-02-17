/*
처음에 dfs로 풀 생각을 했지만, 최대치일때 시간초과가 발생할 것 같아서 dp로 변경
*/

#include <iostream>
using namespace std;

int tree[501][501];
int dp[501][501];
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int maxi = 0;
    cin >> n;
    cin >> tree[0][0];
    dp[0][0] = tree[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> tree[i][j];
            if (j < i)
                dp[i][j] = dp[i - 1][j] + tree[i][j];
            if (j - 1 >= 0)
            {
                if (dp[i - 1][j] + tree[i][j] < dp[i - 1][j - 1] + tree[i][j])
                    dp[i][j] = dp[i - 1][j - 1] + tree[i][j];
            }
            if (i == n - 1)
            {
                if (dp[i][j] > maxi)
                    maxi = dp[i][j];
            }
        }
    }
    n == 1 ? cout << tree[0][0] << "\n" : cout << maxi << "\n";
    return 0;
}