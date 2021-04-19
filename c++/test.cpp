#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> v;

int main(void)
{
    vector<int> a(4, 1);
    v.push_back(a);
    v.push_back(a);

    cout << v.size() << "\n";
    return 0;
}