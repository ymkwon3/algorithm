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
    int n = 123;
    int tmp = 0;
    while (n / 10 != 0)
    {
        tmp += n % 10;
        n /= 10;
    }
    tmp += n;
    cout << tmp << "\n";
    return 0;
}