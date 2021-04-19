#include <string>
#include <vector>

using namespace std;

bool visit[201];

int dfs(int pivot, int index, vector<vector<int>> c)
{

    if (c[pivot][index] == 1 && !visit[index])
    {
        visit[index] = true;
        if (pivot != index)
            dfs(index, 0, c);
    }

    if (index < c.size() - 1)
        dfs(pivot, index + 1, c);

    return 1;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
            answer += dfs(i, 0, computers);
    }
    return answer;
}