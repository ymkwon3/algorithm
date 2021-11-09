#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    map<string, vector<int>> m;
    map<string, vector<int>>::iterator iter;
    vector<vector<string>> v(info.size());
    vector<vector<string>> q(query.size());
    // info 데이터들을 조합으로 모든 경우의 수를 만들기 위해 배열에 저장 후 map에 경우의 수 저장
    for (int i = 0; i < info.size(); i++)
    {
        string tmp = "";
        int score;
        for (char c : info[i])
        {
            if (c == ' ')
            {
                v[i].push_back(tmp);
                tmp = "";
            }
            else
                tmp += c;
        }
        score = stoi(tmp);
        m[v[i][0] + v[i][1] + v[i][2] + v[i][3]].push_back(score);

        m["-" + v[i][1] + v[i][2] + v[i][3]].push_back(score);
        m[v[i][0] + "-" + v[i][2] + v[i][3]].push_back(score);
        m[v[i][0] + v[i][1] + "-" + v[i][3]].push_back(score);
        m[v[i][0] + v[i][1] + v[i][2] + "-"].push_back(score);

        m["--" + v[i][2] + v[i][3]].push_back(score);
        m["-" + v[i][1] + "-" + v[i][3]].push_back(score);
        m["-" + v[i][1] + v[i][2] + "-"].push_back(score);
        m[v[i][0] + "--" + v[i][3]].push_back(score);
        m[v[i][0] + "-" + v[i][2] + "-"].push_back(score);
        m[v[i][0] + v[i][1] + "--"].push_back(score);

        m["---" + v[i][3]].push_back(score);
        m["--" + v[i][2] + "-"].push_back(score);
        m["-" + v[i][1] + "--"].push_back(score);
        m[v[i][0] + "---"].push_back(score);

        m["----"].push_back(score);
    }

    // 이분탐색을 위한 정렬
    for (iter = m.begin(); iter != m.end(); iter++)
        sort(iter->second.begin(), iter->second.end());

    for (int i = 0; i < query.size(); i++)
    {
        string line = "";
        string tmp = "";
        int score;
        for (char c : query[i])
        {
            if (c == ' ')
            {
                if (tmp != "and")
                    line += tmp;
                tmp = "";
            }
            else
                tmp += c;
        }
        score = stoi(tmp);
        int cnt = 0;
        auto itr = lower_bound(m[line].begin(), m[line].end(), score);
        answer.push_back(m[line].size() - (itr - m[line].begin()));
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
        cout << iter->first << " ";

        for (int i = 0; i < iter->second.size(); i++)
        {
            cout << iter->second[i] << " ";
        }
        cout << "\n";
    }

    for (int i : answer)
        cout << i << "\n";
    return answer;
}

int main(void)
{
    solution({"java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"},
             {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"});
    return 0;
}