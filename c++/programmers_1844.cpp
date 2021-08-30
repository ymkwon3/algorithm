#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// dfs로 풀이할 경우 갈래길이 많을 경우 시간이 엄청나게 걸린다....
// void dfs(vector<vector<int>> maps, vector<vector<bool>> &visited, int x, int y, int &distance, int &answer)
// {
//     int mapsX = maps[0].size();
//     int mapsY = maps.size();
//     int dy[] = {1, 0, -1, 0};
//     int dx[] = {0, 1, 0, -1};

//     for (int i = 0; i < 4; i++)
//     {
//         if (x + dx[i] >= 0 && x + dx[i] < mapsX && y + dy[i] >= 0 && y + dy[i] < mapsY)
//         {
//             if (!visited[y + dy[i]][x + dx[i]] && maps[y + dy[i]][x + dx[i]] == 1)
//             {
//                 visited[y][x] = true;
//                 dfs(maps, visited, x + dx[i], y + dy[i], ++distance, answer);
//             }
//         }
//     }
//     if (x == mapsX - 1 & y == mapsY - 1)
//     {
//         if (answer == -1 || answer > distance)
//             answer = distance;
//         cout << distance << "\n";
//     }
//     --distance;
//     visited[y][x] = false;
// }

class Position
{
public:
    int x;
    int y;
    int d;
    Position(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    int mapsX = maps[0].size();
    int mapsY = maps.size();
    vector<bool> e(maps[0].size(), false);
    vector<vector<bool>> visited(maps.size(), e);
    queue<Position> q;
    q.push(Position(0, 0, 1));
    visited[0][0] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] >= 0 && x + dx[i] < mapsX && y + dy[i] >= 0 && y + dy[i] < mapsY)
            {
                if (!visited[y + dy[i]][x + dx[i]] && maps[y + dy[i]][x + dx[i]] == 1)
                {
                    if (x + dx[i] == mapsX - 1 && y + dy[i] == mapsY - 1)
                    {
                        if (answer == -1 || answer > d + 1)
                            answer = d + 1;
                    }
                    visited[y + dy[i]][x + dx[i]] = true;
                    q.push(Position(x + dx[i], y + dy[i], d + 1));
                }
            }
        }
    }
    cout << -1 << "\n";
    return answer;
}

int main()
{
    vector<vector<int>> map = {{1}, {1}, {1}, {1}, {1}};

    solution(map);

    return 0;
}