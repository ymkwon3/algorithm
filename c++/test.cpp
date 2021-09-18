#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

int main(void)
{
    vector<string> address = {"11.114.225.001"};
    vector<string> result;
    for (string s : address)
    {
        string cur = "";
        string ans = "IPv4";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ':')
            {
                ans = "IPv6";
                break;
            }
            if (s[i] == '.')
            {
                if (cur == "" || (cur[0] == '0' && cur[1] != '0' && cur.size() == 3) || stoi(cur) > 255)
                {
                    ans = "Neither";
                    break;
                }
                else
                    cur = "";
            }
            else
            {
                cur += s[i];
            }
            if (i == s.size() - 1)
            {
                if (cur == "" || (cur[0] == '0' && cur[1] != '0' && cur.size() == 3) || stoi(cur) > 255)
                {
                    ans = "Neither";
                    break;
                }
                else
                    cur = "";
            }
        }
        if (ans != "IPv6")
        {
            result.push_back(ans);
            continue;
        }
        cur = "";
        int colons = 0;
        bool skip = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ':')
            {
                if (s[i + 1] == ':')
                {
                    colons++;
                    skip = true;
                }
                colons++;
                if (cur.size() > 4)
                {
                    ans = "Neither";
                    break;
                }
                cur = "";
            }
            else
            {
                if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 102))
                {
                    cur += s[i];
                }
                else
                {
                    ans = "Neither";
                    break;
                }
            }
        }
        if (colons > 7)
            ans = "Neither";
        else if (colons < 7 && ans == "IPv6")
            ans = skip ? "IPv6" : "Neither";
        result.push_back(ans);
    }
    for (string s : result)
        cout << s << "\n";
    return 0;
}