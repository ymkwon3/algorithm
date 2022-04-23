#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = triangle[0][0];
    if (triangle.size() > 1)
    {
        triangle[1][0] = triangle[1][0] + answer;
        triangle[1][1] = triangle[1][1] + answer;
    }
    for (int i = 2; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == triangle[i].size() - 1)
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
            }
            else if (j != 0)
            {
                triangle[i][j] = triangle[i - 1][j] > triangle[i - 1][j - 1] ? triangle[i][j] + triangle[i - 1][j] : triangle[i][j] + triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
            }
            if (i == triangle.size() - 1)
            {
                answer = triangle[i][j] > answer ? triangle[i][j] : answer;
            }
        }
    }
    return answer;
}