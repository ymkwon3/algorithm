#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> places = {{"POOPO", "OOOOO", "OOPOO", "POOOO", "OOOOP"}, {"POOPX", "OXPXP", "OXXXO", "OXXXO", "OOOOO"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

int isP(int i, int j, int k)
{
    if (k + 1 < 5)
    {
        if (places[i][j][k + 1] == 'P')
            return 0;
    }
    if (k + 2 < 5)
    {
        if (places[i][j][k + 1] != 'X' && places[i][j][k + 2] == 'P')
            return 0;
    }
    if (j + 1 < 5)
    {
        if (places[i][j + 1][k] == 'P')
            return 0;
    }
    if (j + 2 < 5)
    {
        if (places[i][j + 1][k] != 'X' && places[i][j + 2][k] == 'P')
            return 0;
    }
    if (k + 1 < 5 && j + 1 < 5)
    {
        if ((places[i][j][k + 1] == 'O' || places[i][j + 1][k] == 'O') && places[i][j + 1][k + 1] == 'P')
            return 0;
    }
    if (k - 1 >= 0 && j + 1 < 5)
    {
        if ((places[i][j][k - 1] == 'O' || places[i][j + 1][k] == 'O') && places[i][j + 1][k - 1] == 'P')
            return 0;
    }
    return 1;
}

int main(void)
{
    vector<int> answer;
    for (int i = 0; i < 5; i++)
    {
        int tmp;
        for (int j = 0; j < 5; j++)
        {
            tmp = 1;
            for (int k = 0; k < 5; k++)
            {
                if (places[i][j][k] == 'P')
                {
                    tmp = isP(i, j, k);
                    if (tmp == 0)
                        break;
                }
            }
            if (tmp == 0)
                break;
        }
        answer.push_back(tmp);
    }

    cout << answer[0] << answer[1] << answer[2] << answer[3] << answer[4];
    return 0;
}