#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
int main(void)
{
    string s = "U 12345";
    int tmp = 0;
    for (int i = 2; i < s.size(); i++)
    {
        tmp *= 10;
        tmp += s[i] - '0';
    }
    cout << tmp;
    return 0;
}