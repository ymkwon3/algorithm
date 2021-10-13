#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    map<string, int> m;
    map<string, int>::iterator iter;
    // 길이가 1인 단어 사전 초기화
    int cnt, j;
    for (cnt = 1, j = 65; cnt <= 26; cnt++, j++)
    {
        string a = "";
        a += (char)j;
        m[a] = cnt;
    }

    string a = "";
    for (int i = 0; i < msg.size(); i++)
    {
        a += msg[i];
        j = 1;
        if (i == msg.size() - 1)
        {
            answer.push_back(m[a]);
            break;
        }
        while (true)
        {
            a += msg[i + j];
            if (m[a] == 0)
            {
                m[a] = cnt++;
                a = a.substr(0, a.size() - 1);
                answer.push_back(m[a]);
                a = "";
                i += j - 1;
                break;
            }
            j++;
        }
    }

    // for (auto a : answer)
    // {
    //     cout << a << "\n";
    // }

    return answer;
}

int main(void)
{
    solution("TOBEORNOTTOBEORTOBEORNOT");
    return 0;
}