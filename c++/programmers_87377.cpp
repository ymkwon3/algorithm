#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<vector<int64_t>> v;
    int64_t xMin = 9999999, xMax = -9999999, yMin = 9999999, yMax = -9999999;
    for (int i = 0; i < line.size(); i++)
    {
        int64_t a = line[i][0];
        int64_t b = line[i][1];
        int64_t e = line[i][2];
        for (int j = i + 1; j < line.size(); j++)
        {
            double bfed, ecaf, adbc;
            int64_t c = line[j][0];
            int64_t d = line[j][1];
            int64_t f = line[j][2];
            adbc = a * d - b * c;
            if (adbc == 0)
                break;
            bfed = b * f - e * d;
            ecaf = e * c - a * f;
            if ((bfed / adbc) - (int64_t)(bfed / adbc) == 0 && (ecaf / adbc) - (int64_t)(ecaf / adbc) == 0)
            {
                v.push_back({(int64_t)bfed / (int64_t)adbc, (int64_t)ecaf / (int64_t)adbc});
                int64_t x = bfed / adbc;
                int64_t y = ecaf / adbc;
                if (x < xMin)
                    xMin = x;
                if (x > xMax)
                    xMax = x;
                if (y < yMin)
                    yMin = y;
                if (y > yMax)
                    yMax = y;
            }
        }
    }
    string s = "";
    for (auto i = xMin; i <= xMax; i++)
        s += '.';
    vector<string> answer(yMax - yMin + 1, s);
    for (int64_t i = 0; i < v.size(); i++)
        answer[v[i][1] - yMin][v[i][0] - xMin] = '*';
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(void)
{
    solution({{0, 1, -1}, {1, 0, -1}, {1, 0, 1}});
    return 0;
}