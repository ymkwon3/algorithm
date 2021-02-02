#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<vector<int>> box; // {x좌표, y좌표, 상자높이, 값, 일 수}
int n, m, h, cnt = 0;    // m : 가로크기, n : 세로크기, h : 상자의 수

void bfs()
{
    int result = 0;
    while (!q.empty())
    {
        if (box[q.front()][1] - 1 >= 0 && box[q.front() - m][3] == 0) // 위쪽
        {
            box[q.front() - m][3] = 1;
            box[q.front() - m][4] += box[q.front()][4];
            q.push(q.front() - m);
        }
        if (box[q.front()][0] + 1 < m && box[q.front() + 1][3] == 0) // 오른쪽
        {
            box[q.front() + 1][3] = 1;
            box[q.front() + 1][4] += box[q.front()][4];
            q.push(q.front() + 1);
        }
        if (box[q.front()][1] + 1 < n && box[q.front() + m][3] == 0) // 아래쪽
        {
            box[q.front() + m][3] = 1;
            box[q.front() + m][4] += box[q.front()][4];
            q.push(q.front() + m);
        }
        if (box[q.front()][0] - 1 >= 0 && box[q.front() - 1][3] == 0) // 왼쪽
        {
            box[q.front() - 1][3] = 1;
            box[q.front() - 1][4] += box[q.front()][4];
            q.push(q.front() - 1);
        }
        if (box[q.front()][2] - 1 >= 1 && box[q.front() - m * n][3] == 0) // 위 박스
        {
            box[q.front() - m * n][3] = 1;
            box[q.front() - m * n][4] += box[q.front()][4];
            q.push(q.front() - m * n);
        }
        if (box[q.front()][2] + 1 <= h && box[q.front() + m * n][3] == 0) // 아래 박스
        {
            box[q.front() + m * n][3] = 1;
            box[q.front() + m * n][4] += box[q.front()][4];
            q.push(q.front() + m * n);
        }
        if (q.size() == 1)
            result = box[q.front()][4] - 1;
        q.pop();
    }
    for (int i = 0; i < cnt; i++)
    {
        if (box[i][3] == 0)
            result = -1;
    }
    cout << result << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    int a, day = 1;

    for (int k = 1; k <= h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a;
                box.push_back(vector<int>{j, i, k, a, day});
                if (a == 1)
                    q.push(cnt);
                cnt++;
            }
        }
    }
    bfs();

    return 0;
}