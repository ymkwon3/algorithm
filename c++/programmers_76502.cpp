#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool checkBracket(string s)
{
    stack<char> stk;
    for (char c : s)
    {
        if (c == '[' || c == '(' || c == '{')
        {
            stk.push(c);
        }
        else
        {
            if (stk.size() == 0)
                return false;
            char cmp = stk.top();
            if ((c == ']' && cmp == '[') || (c == '}' && cmp == '{') || (c == ')' && cmp == '('))
            {
                stk.pop();
            }
            else
                return false;
        }
    }
    if (stk.size() != 0)
        return false;
    return true;
}

int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        s = s.substr(1) + s[0];
        if (checkBracket(s))
            answer++;
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    solution("{");
    return 0;
}