/*
교집합을 제거하는 방법을 처음에 생각했지만, 갑자기 정신이 나갔는지
끝점의 x y 각각 뒤측도 빼야해서 힘들다고 판단했다...왜 그랬지....
*/

#include <iostream>

using namespace std;

int nMap[1025][1025];
int dp[1025][1025];
int n, m;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nMap[i][j];
            dp[i][j] = nMap[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    int x, y, xx, yy;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> xx >> yy;
        cout << dp[xx][yy] - dp[xx][y - 1] - dp[x - 1][yy] + dp[x - 1][y - 1] << "\n";
    }

    return 0;
}

// #include <iostream>

// using namespace std;

// int nMap[1025][1025];
// int dp[1025][1025];
// int n, m;

// void solve(int x, int y, int xx, int yy)
// {
//     int sum = 0;
//     for (int i = x; i <= xx; i++)
//         sum += dp[i][yy] - dp[i][y - 1];

//     cout << sum << "\n";
// }

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> nMap[i][j];
//             dp[i][j] = dp[i][j - 1] + nMap[i][j];
//         }
//     }

//     int x, y, xx, yy;

//     for (int i = 0; i < m; i++)
//     {
//         cin >> x >> y >> xx >> yy;
//         solve(x, y, xx, yy);
//     }

//     return 0;
// }