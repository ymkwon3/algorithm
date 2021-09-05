#include <string>
#include <vector>
#include <iostream>
using namespace std;

int rotate(vector<vector<int>> &border, vector<int> query)
{
    int startX = query[0], startY = query[1];
    int x = startX, y = startY, tmp1 = border[startX][startY], tmp2;
    int min = border[startX][startY];
    char direction = 'R';
    //query [x1, y1, x2, y2]

    while (true)
    {
        if (direction == 'R')
        {
            tmp2 = border[x][y + 1];
            border[x][y + 1] = tmp1;
            y++;
            if (y == query[3])
                direction = 'D';
        }
        else if (direction == 'D')
        {
            tmp2 = border[x + 1][y];
            border[x + 1][y] = tmp1;
            x++;
            if (x == query[2])
                direction = 'L';
        }
        else if (direction == 'L')
        {
            tmp2 = border[x][y - 1];
            border[x][y - 1] = tmp1;
            y--;
            if (y == query[1])
                direction = 'U';
        }
        else if (direction == 'U')
        {
            tmp2 = border[x - 1][y];
            border[x - 1][y] = tmp1;
            x--;
        }
        tmp1 = tmp2;
        min = min > tmp1 ? tmp1 : min;
        if (x == startX && y == startY)
            break;
    }

    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> border;
    vector<int> zero(columns + 1, 0);
    border.push_back(zero);
    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        vector<int> element;
        element.push_back(0);
        for (int j = 0; j < columns; j++)
            element.push_back(value++);
        border.push_back(element);
    }

    for (auto i : queries)
        answer.push_back(rotate(border, i));

    return answer;
}

int main(void)
{
    solution(6, 6, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}});
    return 0;
}