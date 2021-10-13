#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int answer, zero = 0, one = 0;
    char pre = '2';
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c != pre)
        {
            pre = c;
            if (c == '0')
                zero++;
            else
                one++;
        }
    }
    answer = zero < one ? zero : one;
    cout << answer << "\n";
    return 0;
}