#include <iostream>
using namespace std;

int main(void)
{
    int x;
    cin >> x;
    int n = 1;
    while (x > n)
    {
        x -= n;
        n++;
    }
    if (n % 2 == 0)
        cout << x << "/" << n + 1 - x << "\n";
    else
        cout << n + 1 - x << "/" << x << "\n";
    return 0;
}