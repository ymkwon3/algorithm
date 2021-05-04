#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int len = s.size();
    int c = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '+')
        {
            break;
        }
        else if (s[i] == '-')
        {
            answer *= -1;
            break;
        }
        answer += (s[i] - 48) * c;
        c *= 10;
    }
    return answer;
}