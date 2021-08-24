#include <string>
#include <vector>
#include <iostream>
#include <queue>
const int MAX = 5;

using namespace std;

class Position
{
public:
    int x;
    int y;
    int distance;
    Position(int _x, int _y, int _distance) : x(_x), y(_y), distance(_distance){};
};

int bfs(vector<string> v, int x, int y)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    queue<Position> q;
    q.push(Position(x, y, 0));
    while (!q.empty())
    {
        // 4방향 검색
        for (int i = 0; i < 4; i++)
        {
            int calX = q.front().x + dx[i];
            int calY = q.front().y + dy[i];
            if (calX >= 0 && calX < MAX &&
                calY >= 0 && calY < MAX &&
                (calX != x || calY != y))
            {
                if (v[calY][calX] == 'O' && q.front().distance == 0)
                {
                    q.push(Position(calX, calY, 1));
                }
                else if (v[calY][calX] == 'P')
                {
                    return 0;
                }
            }
        }
        q.pop();
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for (int i = 0; i < places.size(); i++)
    {
        int result = 1;
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                if (places[i][j][k] == 'P')
                {
                    result = bfs(places[i], k, j);
                }
                if (!result)
                    break;
            }
            if (!result)
                break;
        }
        answer.push_back(result);
    }
    return answer;
}

int main(void)
{
    vector<vector<string>> v = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    solution(v);
    return 0;
}