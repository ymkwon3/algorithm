#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>

using namespace std;

vector<bool> v;
int main(void)
{
    v.push_back(true);
    v.push_back(true);
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);

    cout << count(v.at(0), v.end(), true);

    return 0;
}