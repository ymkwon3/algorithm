#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    stack<char> l;
    stack<char> r;
    for (int i = 0; i < s.size(); i++)
        l.push(s[i]);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char input;
        cin >> input;
        if (input == 'P')
        {
            char c;
            cin >> c;
            l.push(c);
        }
        else if (input == 'L')
        {
            if (l.empty())
                continue;
            else
            {
                r.push(l.top());
                l.pop();
            }
        }
        else if (input == 'B')
        {
            if (l.empty())
                continue;
            else
                l.pop();
        }
        else if (input == 'D')
        {
            if (r.empty())
                continue;
            else
            {
                l.push(r.top());
                r.pop();
            }
        }
    }
    while (!l.empty())
    {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty())
    {
        cout << r.top();
        r.pop();
    }
    return 0;
}

// string 구간을 나눠 커서에 따라 명령실행 = 시간초과
// int main(void)
// {
//     string s;
//     cin >> s;
//     int N = s.length();
//     int cursor = s.length();
//     int m;
//     cin >> m;
//     char c, add;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> c;
//         if (c == 'P')
//         {
//             cin >> add;
//             s = s.substr(0, cursor) + add + s.substr(cursor, N);
//             cursor++, N++;
//         }
//         if (c == 'L' && cursor != 0)
//             cursor--;
//         if (c == 'D' && cursor < N)
//             cursor++;
//         if (c == 'B' && cursor != 0)
//         {
//             s = s.substr(0, cursor - 1) + s.substr(cursor, N);
//             cursor--, N--;
//         }
//     }
//     cout << s << "\n";
//     return 0;
// }