#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>

using namespace std;
map<int, vector<int>> m;
vector<int> v;
vector<int>::iterator iter = v.begin();

int main(void)
{
    int a;
    while (true)
    {
        cin >> a;
        if (cin.eof() == true)
            break;
        cout << a << "\n";
    }
    return 0;
}