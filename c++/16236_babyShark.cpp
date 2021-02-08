/*
bfs로 현재 먹을 수 있는 먹이의 최소 경로를 전체 구한 후
위, 왼쪽 우선순위의 먹이를 먹을 수 있도록 비교정렬 후
먹이를 먹고 bfs 반복

방문처리를 늦게 해주면 그 만큼 값이 원소에 더 들어갈 수 있어 메모리 초과가 난다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

queue<pair<pair<int, int>, int>> q;
vector<pair<pair<int, int>, int>> feed;
int area[21][21];
bool visit[21][21] = {
    {
        false,
    },
};
int n, sharkSize = 2, seconds = 0, evolve = 0;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.first == b.first.first)
            return a.first.second < b.first.second;
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

void bfs()
{
    while (!q.empty())
    {
        int cy = q.front().first.first;
        int cx = q.front().first.second;

        if (area[cy][cx] < sharkSize && area[cy][cx] != 0)
        {
            feed.push_back(make_pair(make_pair(cy, cx), q.front().second));
        }
        if (cy - 1 >= 0 && !visit[cy - 1][cx] && area[cy - 1][cx] <= sharkSize) // up
        {
            visit[cy - 1][cx] = true;
            q.push(make_pair(make_pair(cy - 1, cx), q.front().second + 1));
        }
        if (cx - 1 >= 0 && !visit[cy][cx - 1] && area[cy][cx - 1] <= sharkSize) // left
        {
            visit[cy][cx - 1] = true;
            q.push(make_pair(make_pair(cy, cx - 1), q.front().second + 1));
        }
        if (cx + 1 < n && !visit[cy][cx + 1] && area[cy][cx + 1] <= sharkSize) // right
        {
            visit[cy][cx + 1] = true;
            q.push(make_pair(make_pair(cy, cx + 1), q.front().second + 1));
        }
        if (cy + 1 < n && !visit[cy + 1][cx] && area[cy + 1][cx] <= sharkSize) // down
        {
            visit[cy + 1][cx] = true;
            q.push(make_pair(make_pair(cy + 1, cx), q.front().second + 1));
        }

        q.pop();
    }

    if (!feed.empty())
    {
        sort(feed.begin(), feed.end(), cmp);
        seconds += feed[0].second;
        ++evolve;
        if (evolve == sharkSize)
        {
            sharkSize++;
            evolve = 0;
        }
        area[feed[0].first.first][feed[0].first.second] = 0;
        q.push(make_pair(make_pair(feed[0].first.first, feed[0].first.second), 0));
        fill(visit[0], visit[21], false);
        feed.clear();
        bfs();
        return;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> area[i][j];
            if (area[i][j] == 9)
            {
                q.push(make_pair(make_pair(i, j), 0));
                area[i][j] = 0;
            }
        }
    }
    bfs();
    cout << seconds << "\n";

    return 0;
}