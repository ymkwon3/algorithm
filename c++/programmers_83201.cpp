#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores)
{
    string answer = "";
    for (int i = 0; i < scores[0].size(); i++)
    {
        int min = scores[i][i];
        int max = scores[i][i];
        int sum = 0;
        int cnt = scores.size();
        bool minB = true;
        bool maxB = true;
        for (int j = 0; j < cnt; j++)
        {
            if (i != j && min >= scores[j][i])
            {
                minB = false;
            }
            if (i != j && max <= scores[j][i])
            {
                maxB = false;
            }
            sum += scores[j][i];
        }
        if (minB)
        {
            sum -= scores[i][i];
            cnt--;
        }
        if (maxB)
        {
            sum -= scores[i][i];
            cnt--;
        };
        int mean = sum / cnt;
        if (mean >= 90)
        {
            answer += 'A';
        }
        else if (mean >= 80)
        {
            answer += 'B';
        }
        else if (mean >= 70)
        {
            answer += 'C';
        }
        else if (mean >= 50)
        {
            answer += 'D';
        }
        else
        {
            answer += 'F';
        }
    }

    return answer;
}