/*
가로 조건 2
세로 조건 2
대각선 조건 3
*/

#include <iostream>
#define MAX 17
using namespace std;

int house[MAX][MAX];
int dp[3][MAX][MAX];
int n;

bool check(int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && y <= n && house[x][y] == 0)
        return true;
    return false;
}

void solve()
{
    dp[0][1][2] = 1;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (check(row, col - 1) && check(row, col))
                dp[0][row][col] += dp[0][row][col - 1] + dp[2][row][col - 1];
            if (check(row - 1, col) && check(row, col))
                dp[1][row][col] += dp[1][row - 1][col] + dp[2][row - 1][col];
            if (check(row - 1, col - 1) && check(row - 1, col) && check(row, col - 1) && check(row, col))
                dp[2][row][col] += dp[0][row - 1][col - 1] + dp[1][row - 1][col - 1] + dp[2][row - 1][col - 1];
        }
    }
    cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n] << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> house[i][j];
    solve();

    return 0;
}