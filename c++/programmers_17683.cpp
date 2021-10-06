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
    cout << "result : " << result << "\n";
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
    cout << "find : " << result << "\n";
    return result;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    for (string s : musicinfos)
    {
        int time = setTime(s.substr(0, 5), s.substr(6, 5));
        string a = setAns(s);
        string sheet = setSheet(s);
        string tmp = "";
        bool trigger = false;
        cout << time << "\n";
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
        cout << "tmp : " << tmp << "\n";
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
                    answer = a;
                    cout << "the answer is " << answer << "\n";
                    trigger = true;
                    break;
                }
                else if (tmp.find(m) == -1)
                    break;
            }
        }
        if (trigger)
            break;
    }
    return answer;
}

int main(void)
{
    solution("CCB", {"03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"});
    return 0;
}