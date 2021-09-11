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
int calc(string a, string b)
{
    int aH = stoi(a.substr(0, 2)), aM = stoi(a.substr(3, 2));
    int bH = stoi(b.substr(0, 2)), bM = stoi(b.substr(3, 2));
    if (bM > aM)
    {
        aH--;
        aM += 60;
    }
    return (aH - bH) * 60 + (aM - bM);
}
int main(void)
{
    string s = "23:59 06:05 77:77";
    s = s.substr(12);
    cout << s;
    return 0;
}