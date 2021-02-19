#include <iostream>
using namespace std;

int a, b;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int cnt = 0;
    while (b > a)
    {
        if (b % 10 == 1)
        {
            b -= 1;
            b /= 10;
        }
        else if (b % 2 == 0)
            b /= 2;
        else
            break;
        cnt++;
        if (a == b)
        {
            cout << cnt + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}