#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s)
{
    string tmp;
    int ans = 0, zero = 0, cnt = 0;
    while (s != "1")
    {
        tmp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                ans++;
            else
                zero++;
        }
        while (ans != 0)
        {
            tmp += (ans % 2 == 0 ? "0" : "1");
            ans /= 2;
        }
        cnt++;
        s = tmp;
    }

    cout << cnt << " : " << zero;

    vector<int> answer = {cnt, zero};

    return answer;
}

int main(void)
{
    solution("01110");
    return 0;
}