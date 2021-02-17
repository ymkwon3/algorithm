#include <iostream>
typedef unsigned long long ull;
using namespace std;

ull a, b, c, r = 1;
ull n;

void solve(ull aa)
{
    ull arg = aa;
    while (arg > 1)
    {
        arg % 2 == 1 ? r *= n : r *= 1;
        arg /= 2;
        n *= n;
        n %= c;
        r %= c;
    }

    cout << (n * r) % c << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    n = a % c;
    solve(b);
    return 0;
}