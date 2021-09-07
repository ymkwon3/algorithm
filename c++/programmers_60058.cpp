#include <string>
#include <vector>
#include <iostream>
using namespace std;

string reverseString(string s)
{ // 괄호 방향 뒤집기
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
    }
    return s;
}

string returnString(string s)
{
    string tmp = "";
    if (s.size() == 0)
        return tmp;
    string u, v;
    int stk = 0;
    bool isTrue = true; // 올바른 괄호 문자열인지 판별
    for (int i = 0; i < s.size(); i++)
    { // u, v 분리 과정
        if (stk < 0)
            isTrue = false;
        if (s[i] == '(')
            stk++;
        else
            stk--;
        if (stk == 0)
        {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1, s.size());
            break;
        }
    }

    if (isTrue) // u가 올바른 괄호 문자열일 경우
    {
        tmp += u + returnString(v);
    }
    else // u가 올바른 괄호 문자열이 아닐 경우
    {
        tmp += '(' + returnString(v) + ')' + reverseString(u.substr(1, u.size() - 2));
    }

    return tmp;
}

string solution(string p)
{
    string answer = "";
    answer = returnString(p);
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution(")))(()((");

    return 0;
}