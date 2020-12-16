#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> board;
vector<string> whiteBoard;
vector<string> blackBoard;
int n, m;

void init()
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            whiteBoard.push_back("WBWBWBWB");
            blackBoard.push_back("BWBWBWBW");
        }
        else
        {
            whiteBoard.push_back("BWBWBWBW");
            blackBoard.push_back("WBWBWBWB");
        }
    }

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        vector<char> element(m, 'N');
        board.push_back(element);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
}

int whiteStart(int a, int b)
{
    int cnt = 0;
    for (int i = a, q = 0; i < a + 8; i++, q++)
    {
        for (int j = b, w = 0; j < b + 8; j++, w++)
        {
            if (board[i][j] != whiteBoard[q][w])
                cnt++;
        }
    }
    return cnt;
}

int blackStart(int a, int b)
{
    int cnt = 0;
    for (int i = a, q = 0; i < a + 8; i++, q++)
    {
        for (int j = b, w = 0; j < b + 8; j++, w++)
        {
            if (board[i][j] != blackBoard[q][w])
                cnt++;
        }
    }
    return cnt;
}

void solve()
{
    int minimum = 99;
    int black, white;
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            minimum = min(minimum, blackStart(i, j));
            minimum = min(minimum, whiteStart(i, j));
        }
    }
    cout << minimum << "\n";
}

int main(void)
{
    init();
    solve();
    return 0;
}