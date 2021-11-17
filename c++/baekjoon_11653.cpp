#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n;
    while (n != 1)
    {
        m = 2;
        while (true)
        {
            if (n % m == 0)
            {
                cout << m << "\n";
                n /= m;
                break;
            }
            m++;
        }
    }
    return 0;
}