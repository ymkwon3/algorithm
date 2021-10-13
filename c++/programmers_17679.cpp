#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void check(int x, int y, vector<string> &board, bool &re, vector<vector<bool>> &visit, vector<vector<bool>> &checkBoard)
{
    visit[x][y] = true;
    if (x < board.size() - 1 && y < board[0].size() - 1 && board[x][y] - board[x + 1][y] == 0 && board[x][y] - board[x + 1][y + 1] == 0 && board[x][y] - board[x][y + 1] == 0)
    {
        if (!visit[x + 1][y])
            check(x + 1, y, board, re, visit, checkBoard);
        if (!visit[x + 1][y + 1])
            check(x + 1, y + 1, board, re, visit, checkBoard);
        if (!visit[x][y + 1])
            check(x, y + 1, board, re, visit, checkBoard);
        checkBoard[x][y] = true, checkBoard[x + 1][y] = true, checkBoard[x][y + 1] = true, checkBoard[x + 1][y + 1] = true;
        re = true;
    }
    if (x < board.size() - 1 && 0 <= y - 1 && board[x][y] - board[x + 1][y] == 0 && board[x][y] - board[x + 1][y - 1] == 0 && board[x][y] - board[x][y - 1] == 0)
    {
        if (!visit[x + 1][y])
            check(x + 1, y, board, re, visit, checkBoard);
        if (!visit[x + 1][y - 1])
            check(x + 1, y - 1, board, re, visit, checkBoard);
        if (!visit[x][y - 1])
            check(x, y - 1, board, re, visit, checkBoard);
        checkBoard[x][y] = true, checkBoard[x + 1][y] = true, checkBoard[x][y - 1] = true, checkBoard[x + 1][y - 1] = true;
        re = true;
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    vector<bool> v(n);
    while (true)
    {
        bool re = false;
        vector<vector<bool>> visit(m, v);
        vector<vector<bool>> checkBoard(m, v);
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (!visit[i][j] && board[i][j] - '-' != 0)
                    check(i, j, board, re, visit, checkBoard);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (checkBoard[i][j])
                    board[i][j] = '-';
            }
        }

        if (re)
        {
            stack<char> stk;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[j][i] - '-' != 0)
                    {
                        stk.push(board[j][i]);
                        board[j][i] = '-';
                    }
                }
                for (int j = m - 1; !stk.empty(); j--)
                {
                    board[j][i] = stk.top();
                    stk.pop();
                }
            }
        }
        else
            break;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] - '-' == 0)
                answer++;
        }
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    solution(6, 6, {"AABBEE", "AAAEEE", "VAAEEV", "AABBEE", "AACCEE", "VVCCEE"});
    return 0;
}