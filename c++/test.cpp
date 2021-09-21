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
    string b = "abcde";
    string a = "";
    a += b[0], a += b[1];
    cout << a << "\n";
    return 0;
}