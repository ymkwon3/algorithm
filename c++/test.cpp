#include <iostream>
#include <vector>

using namespace std;

vector<int> test;

int main(void)
{
    test.push_back(100);
    test.push_back(200);
    test.push_back(300);
    test.push_back(400);

    test.erase(test.begin() + 2);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << "\n";
    }

    return 0;
}