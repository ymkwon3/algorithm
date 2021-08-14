#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, type, mark;
    string name;
    map<string, int> m;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> name >> mark;
            m[name] = m[name] + mark;
        }
        else if (type == 2)
        {
            cin >> name;
            m[name] = 0;
        }
        else if (type == 3)
        {
            cin >> name;
            cout << m[name] << "\n";
            // if (m[name] == -1)
            //     cout << 0 << "\n";
            // else if (m[name] != 0)
                }
    }
    return 0;
}
