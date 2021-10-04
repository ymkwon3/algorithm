#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
    string s = "abcde";
    for (int i = 0; i < s.size(); i++)
    {
        s = s.substr(1) + s[0];
        cout << s << "\n";
    }
    return 0;
}
// 6 2 1