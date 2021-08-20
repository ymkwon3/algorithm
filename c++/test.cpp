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
    vector<int> i = {1, 0, 0};
    vector<int> j = i;
    cout << j[0] << j[1] << j[2] << "\n";
    return 0;
}