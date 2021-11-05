#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dfs(int n, int k, vector<vector<int>> dungeons, int c, vector<int> v)
{
    int result = c - 1;
    v[n] = 1;
    if (k >= dungeons[n][0])
    {

        k -= dungeons[n][1];
        result++;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (v[i] == 0)
            {
                int tmp = dfs(i, k, dungeons, c + 1, v);
                if (tmp > result)
                    result = tmp;
            }
        }
    }
    return result;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    vector<int> v(dungeons.size());
    for (int i = 0; i < dungeons.size(); i++)
    {
        int tmp = dfs(i, k, dungeons, 1, v);
        if (tmp > answer)
            answer = tmp;
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    solution(80, {{80, 20}, {50, 40}, {30, 10}});
    return 0;
}