#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[501][501][4];
// 0 1 2 3 up left down right
int getCycle(int y, int x, int dir, vector<string> &grid)
{
    int len = 0;
    while (true)
    {
        if (visited[y][x][dir])
            break;
        visited[y][x][dir] = true;
        len++;

        if (grid[y][x] == 'L')
            dir = dir != 3 ? dir + 1 : 0;
        else if (grid[y][x] == 'R')
            dir = dir != 0 ? dir - 1 : 3;

        if (dir == 0)
        {
            if (y == 0)
                y = grid.size();
            y--;
        }
        else if (dir == 1)
        {
            if (x == 0)
                x = grid[y].size();
            x--;
        }
        else if (dir == 2)
        {
            if (y == grid.size() - 1)
                y = -1;
            y++;
        }
        else if (dir == 3)
        {
            if (x == grid[y].size() - 1)
                x = -1;
            x++;
        }
    }
    return len;
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (visited[i][j][k])
                    continue;
                answer.push_back(getCycle(i, j, k, grid));
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(void)
{
    solution({"SL", "LR"});
    return 0;
}