#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;
    map<int, int> m;
    string tmp = "";
    for (char i : s)
    {
        if (i >= 48 && i <= 57)
        {
            tmp += i;
        }
        else
        {
            if (tmp != "")
            {
                m[stoi(tmp)]++;
                tmp = "";
            }
        }
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (pair<int, int> i : v)
    {
        answer.push_back(i.first);
    }

    return answer;
}

int main(void)
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    solution(s);
    return 0;
}