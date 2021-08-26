#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    a.erase(a.begin());
    for (auto i : a)
        cout << i << " ";
    return 0;
}