#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>

using namespace std;
map<int, vector<int>> m;
int main(void)
{
    m[1].push_back(1);
    m[1].push_back(6);
    cout << m[1][1] << "\n";
    return 0;
}