/*
결과값은 모든 값을 더한 후, -값의 최대 * 2를 더한 값과 같다.
*/

#include <iostream>
using namespace std;

string s;

void init()
{
    cin >> s;
}

void solve()
{
    int sum = 0; // 모든 값의 합
    int minusValue = 0;
    bool isMinus = false;
    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            sum += stoi(tmp);
            if (isMinus)
            {
                minusValue += stoi(tmp);
            }
            tmp.clear();
            isMinus = true;
        }
        else if (s[i] != '+') // 숫자일 경우
        {
            tmp.push_back(s[i]);
        }
        if (s[i] == '+' || i == s.size() - 1)
        {
            sum += stoi(tmp);
            if (isMinus)
            {
                minusValue += stoi(tmp);
            }
            tmp.clear();
        }
    }
    cout << sum - minusValue * 2 << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}