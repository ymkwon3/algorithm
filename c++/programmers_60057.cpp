#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++)
    {
        string tmp = s.substr(0, i);
        string conv;
        int cnt = 1;
        for (int j = i; j < s.size(); j += i)
        {
            if (s.substr(j, i) == tmp)
                cnt++;
            else
            {
                if (cnt > 1)
                    conv += to_string(cnt);
                conv += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt > 1)
            conv += to_string(cnt);
        conv += tmp;
        answer = answer < conv.size() ? answer : conv.size();
    }
    return answer;
}

int main()
{
    solution("abcabcabcabcdededededede");
    return 0;
}