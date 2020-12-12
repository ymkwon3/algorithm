#include <iostream>
using namespace std;

int n, layer = 2;
int num = 7, cnt = 6;

void init()
{
    cin >> n;
}

void solve()
{
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    while (true)
    {
        if (n <= num)
        {
            cout << layer << "\n";
            return;
        }
        cnt += 6;
        num += cnt;
        layer++;
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}