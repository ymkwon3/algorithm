#include <string>
#include <vector>
#include <iostream>
using namespace std;

void attack(vector<vector<int>> &board, int sX, int eX, int sY, int eY, int amount)
{
    for (int i = sX; i <= eX; i++)
        for (int j = sY; j <= eY; j++)
            board[i][j] -= amount;
}

void heal(vector<vector<int>> &board, int sX, int eX, int sY, int eY, int amount)
{
    for (int i = sX; i <= eX; i++)
        for (int j = sY; j <= eY; j++)
            board[i][j] += amount;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    for (auto i : skill)
    {
        if (i[0] == 1)
            attack(board, i[1], i[3], i[2], i[4], i[5]);
        else
            heal(board, i[1], i[3], i[2], i[4], i[5]);
    }
    for (auto i : board)
    {
        for (auto j : i)
        {
            if (j > 0)
                answer++;
        }
    }
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution({
                 {5, 5, 5, 5, 5},
                 {5, 5, 5, 5, 5},
                 {5, 5, 5, 5, 5},
                 {5, 5, 5, 5, 5},
             },
             {{1, 0, 0, 3, 4, 4}, {1, 2, 0, 2, 3, 2}, {2, 1, 0, 3, 1, 2}, {1, 0, 1, 3, 3, 1}});
    return 0;
}