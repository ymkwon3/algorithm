#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>

using namespace std;
int main(void)
{
    map<int, int> m;

    m[0]++;
    m[5]++;
    m[5]++;
    m[7]++;
    m[-1]++;
    m.erase(7);
    m[7]++;
    cout << m.begin()->first << "\n";
    cout << m.rbegin()->first << "\n";
    return 0;
}