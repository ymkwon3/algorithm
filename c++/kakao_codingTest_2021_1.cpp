#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, int> m;
int main(void)
{
    string s = "one4seveneight";
    string tmp;
    int answer = 0;
    m.insert({"zero", 0});
    m.insert({"one", 1});
    m.insert({"two", 2});
    m.insert({"three", 3});
    m.insert({"four", 4});
    m.insert({"five", 5});
    m.insert({"six", 6});
    m.insert({"seven", 7});
    m.insert({"eight", 8});
    m.insert({"nine", 9});

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            answer *= 10;
            answer += s[i] - '0';
        }
        else
        {
            tmp.push_back(s[i]);
            if (m.find(tmp) != m.end())
            {
                answer *= 10;
                answer += m[tmp];
                tmp = "";
            }
        }
    }

    cout << answer << "\n";
    return 0;
}