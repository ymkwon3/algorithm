#include <iostream>

using namespace std;

int n;

void init()
{
    cin >> n;
}

int disassemblySum(int i)
{
    int sum = 0;
    while (i)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

void solve()
{
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        result = disassemblySum(i);
        if (i + result == n)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main(void)
{
    init();
    solve();
    return 0;
}