#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    char c = s[s.size() - 2];
    if (c == 'A')
    {
        if (stoi(s.substr(0, 2)) == 12)
            return "00" + s.substr(2, s.size() - 4);
        return s.substr(0, s.size() - 2);
    }
    else
    {
        if (stoi(s.substr(0, 2)) == 12)
            return s.substr(0, s.size() - 2);
        return to_string(stoi(s.substr(0, 2)) + 12) + s.substr(2, s.size() - 4);
    }
}

int main()
{
    timeConversion("12:40:22AM");
    return 0;
}