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
    string a = "abcde";
    string b = a.substr(2, a.size());
    cout << a.substr(0, 2) << " " << b << "\n";
    return 0;
}