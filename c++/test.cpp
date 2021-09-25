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

int main(void)
{
    int a = 1;
    int b = 10;
    while (a < b)
    {
        cout << a << " " << b << "\n";
        a += 2;
        b++;
    }
}