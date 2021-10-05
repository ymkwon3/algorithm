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
    int n = 6;
    string tmp = "";
    while (n != 0)
    {
        tmp = to_string(n % 2) + tmp;
        n /= 2;
    }
    cout << tmp;
    return 0;
}