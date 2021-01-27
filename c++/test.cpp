#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> test(5);

int main(void)
{
    test[1].push_back(8);
    cout << test[2].size() << "\n";
    return 0;
}