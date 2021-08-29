#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string param)
{
    vector<string> v;
    stringstream ss(param);
    string temp;

    while (getline(ss, temp, ' '))
    {
        v.push_back(temp);
    }
    return v;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    map<string, string> m;
    for (string value : record)
    {
        vector<string> tmp = split(value);
        cout << tmp[0] << "\n";
        if (tmp[0] == "Enter" || tmp[0] == "Change")
        {
            cout << tmp[1] << " " << tmp[2] << "\n";
            m[tmp[1]] = tmp[2];
        }
    }

    for (string value : record)
    {
        vector<string> tmp = split(value);
        if (tmp[0] == "Enter")
            answer.push_back(m[tmp[1]] + "님이 들어왔습니다.");
        else if (tmp[0] == "Leave")
            answer.push_back(m[tmp[1]] + "님이 나갔습니다.");
    }

    return answer;
}

int main(void)
{
    vector<string> v = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    solution(v);
    return 0;
}