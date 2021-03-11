#include <iostream>
#define MAX 15
using namespace std;
int board[MAX];
int n, cnt;

bool check(int row)
{
    for (int i = 0; i < row; i++)
        if (board[i] == board[row] || abs(board[row] - board[i]) == row - i)
            return false;
    return true;
}

void nQueen(int row)
{
    if (row == n)
        cnt++;
    else
    {
        for (int col = 0; col < n; col++)
        {
            board[row] = col;
            if (check(row))
                nQueen(row + 1);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    nQueen(0);
    cout << cnt << "\n";
    return 0;
}