#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    map<string, int> m;
    map<string, int>::iterator iter;
    map<string, int> cnt;
    map<string, int> userCnt;
    for (int i = 0; i < report.size(); i++)
    {
        if (m[report[i]] == 0)
        {
            m[report[i]] = 1;
            cnt[report[i].substr(report[i].find(" ") + 1)]++;
        }
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        string s = iter->first;
        string user = s.substr(0, s.find(" "));
        string target = s.substr(s.find(" ") + 1);
        if (cnt[target] >= k)
        {
            userCnt[user]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        answer.push_back(userCnt[id_list[i]]);
        cout << answer[i] << " ";
    }
    return answer;
}

int main(void)
{
    solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 1);
    return 0;
}