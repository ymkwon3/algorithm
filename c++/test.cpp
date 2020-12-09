#include <iostream>
#include <vector>

using namespace std;

vector<int> a[10];

int main(void)
{
    a[0].push_back(1);
    a[1].push_back(0);

    a[0].push_back(2);
    a[2].push_back(0);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}