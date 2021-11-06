#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>
#include <math.h>
using namespace std;

int main()
{
    vector<int> perm = {0, 1, 2};
    for (int i : perm)
    {
        if (i == 1)
            perm.erase(perm.begin() + 1);
        cout << i << "\n";
    }
    for (int i : perm)
    {
        cout << i << "\n";
    }
    return 0;
}