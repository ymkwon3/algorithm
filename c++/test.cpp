#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

map<int, int> testMap;
vector<vector<int>> test(5);

int main(void)
{
    auto a = 0;

    cin >> a;
    cout << typeid(a).name() << " " << a << "\n";

    cin >> a;
    cout << typeid(a).name() << " " << a << "\n";
    return 0;
}