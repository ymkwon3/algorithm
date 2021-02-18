#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>

using namespace std;
map<int, vector<int>> m;
vector<int> v;
vector<int>::iterator iter = v.begin();

int main(void)
{
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.erase(iter + 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
    return 0;
}