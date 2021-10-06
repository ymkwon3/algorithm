#include <iostream>
#include <string>
#include <vector>

using namespace std;

int setTime(string start, string end)
{
    return (stoi(end.substr(0, 2)) - stoi(start.substr(0, 2))) * 60 + stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));
}

string setSheet(string s)
{
    string result = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ',')
            break;
        result = s[i] + result;
    }
    return result;
}

string setAns(string s)
{
    string result = "";
    bool trigger = false;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ',' && !trigger)
            trigger = true;
        else if (s[i] == ',' && trigger)
            break;
        else if (trigger)
            result = s[i] + result;
    }
    return result;
}

int setInputTime(string s)
{
    s = s.substr(0, 2) + s.substr(3, 2);
    return stoi(s);
}

string solution(string m, vector<string> musicinfos)
{
    pair<string, int> answer = {"", 0};
    int st = 0;
    for (string s : musicinfos)
    {
        int time = setTime(s.substr(0, 5), s.substr(6, 5));
        int startTime = setInputTime(s.substr(0, 5));
        string a = setAns(s);
        string sheet = setSheet(s);
        string tmp = "";
        int i = 0;
        while (time != 0)
        {
            if (i == sheet.size())
                i = 0;
            if (i + 1 != sheet.size() && sheet[i + 1] == '#')
            {
                tmp = tmp + sheet[i] + sheet[i + 1];
                i += 2;
            }
            else
            {
                tmp += sheet[i];
                i++;
            }
            time--;
        }
        if (tmp.find(m) != -1)
        {
            while (true)
            {
                if (tmp.find(m) != string::npos && tmp[tmp.find(m) + m.size()] == '#')
                {
                    tmp = tmp.substr(tmp.find(m) + m.size() - 1);
                }
                else if (tmp.find(m) != string::npos && tmp[tmp.find(m) + m.size()] != '#')
                {
                    if (answer.first == "")
                    {
                        answer = {a, time};
                        st = startTime;
                    }
                    else
                    {
                        if (answer.second < time)
                            answer = {a, time};
                        else if (answer.second == time)
                        {
                            if (st > startTime)
                            {
                                answer = {a, time};
                                // st = startTime;
                                // 이 부분 적용되어야 하는게 맞는것 같은데... 적용하면 tc 21이 틀렸다고함...
                            }
                        }
                    }
                    break;
                }
                else if (tmp.find(m) == -1)
                    break;
            }
        }
    }
    if (answer.first == "")
        answer.first = "(None)";
    return answer.first;
}

int main(void)
{
    solution("CDEFGAC", {"00:01,00:10,HELLO,CDEFGA"});
    return 0;
}