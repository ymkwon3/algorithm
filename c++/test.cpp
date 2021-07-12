#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
const int COUNT = 100;

vector<vector<int>> a;
int main(void)
{
    int num;
    double cnt10 = 0, cnt90 = 0;
    for (int i = 0; i < COUNT; i++)
    {
        num = rand() % 10;
        if (num == 0)
        {
            cnt10++;
        }
        else
        {
            cnt90++;
        }
    }
    cout << "10 : " << (cnt10 / COUNT) << "\n";
    cout << "90 : " << (cnt90 / COUNT) << "\n";

    return 0;
}