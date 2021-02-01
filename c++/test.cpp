#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

map<int, int> testMap;
vector<vector<int>> test;

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        vector<int> e;
        test.push_back(e);
    }
    test[0].push_back(3);
    test[0].push_back(5);
    test[1].push_back(1);
    test[2].push_back(7);

    cout << test[0][0] << "\n";
    cout << test[0][1] << "\n";
    cout << test[1][0] << "\n";
    cout << test[2][0] << "\n";
    return 0;
}