#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> v(5);
int main(void)
{
    v[3].push_back(1);
    v[3].push_back(2);
    v[3].push_back(3);
    cout << v[3][1];
    return 0;
}