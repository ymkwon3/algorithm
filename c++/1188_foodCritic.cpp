#include <iostream>
using namespace std;

int slice(int a, int b)
{
    if (a % b == 0)
        return b;
    return slice(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << m - slice(n, m) << "\n";
    return 0;
}