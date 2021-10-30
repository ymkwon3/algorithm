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
    string s = "abcde";
    s = s.substr(0, 5) + 'A' + s.substr(5, 5);
    cout << s << "\n";
    return 0;
}