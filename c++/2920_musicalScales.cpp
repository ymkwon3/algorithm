#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void init()
{
    for (int i = 0, j = 0; i < 8; i++)
    {
        cin >> j;
        a.push_back(j);
    }
}

void solve()
{
    int tmp = 0;
    for (int i = 0, pre = 0; i < 8; i++)
    {
        if (i == 0)
            pre = a[i];
        else
        {
            tmp = a[i] - pre;
            pre = a[i];
            if (tmp != 1 && tmp != -1)
            {
                cout << "mixed"
                     << "\n";
                break;
            }
            if (i == 7)
            {
                if (tmp == 1)
                    cout << "ascending"
                         << "\n";
                if (tmp == -1)
                    cout << "descending"
                         << "\n";
            }
        }
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}