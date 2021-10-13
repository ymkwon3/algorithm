#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cnt, type, input;
    set<int> s;
    set<int>::iterator itr;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> type >> input;
        if (type == 1)
        {
            s.insert(input);
        }
        else if (type == 2)
        {
            s.erase(input);
        }
        else if (type == 3)
        {
            itr = s.find(input);
            if (itr == s.end())
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
    return 0;
}
