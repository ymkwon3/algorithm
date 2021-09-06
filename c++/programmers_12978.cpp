#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    vector<vector<pair<int, int>>> graph(51, vector<pair<int, int>>());
    vector<int> time(51, 0);
    time[0] = -1;
    time[1] = -1;
    queue<pair<int, int>> q;

    for (auto i : road)
    {
        graph[i[0]].push_back({i[1], i[2]});
        graph[i[1]].push_back({i[0], i[2]});
    }
    q.push({1, 0});
    while (!q.empty())
    {
        int node = q.front().first;
        int len = q.front().second;
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (time[graph[node][i].first] == 0 || time[graph[node][i].first] > graph[node][i].second + len)
            {
                time[graph[node][i].first] = graph[node][i].second + len;
                q.push({graph[node][i].first, graph[node][i].second + len});
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        answer += time[i] > K ? 0 : 1;
    }
    cout << "answer " << answer << "\n";
    return answer;
}

int main()
{
    solution(5, {{1, 2, 1}, {5, 2, 1}, {1, 4, 1}, {5, 4, 1}, {5, 3, 2}}, 3);
    return 0;
}