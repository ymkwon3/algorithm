#include <iostream>
using namespace std;

int sum(int n)
{
    int tmp;
    while (true)
    {
        tmp = 0;
        while (n / 10 != 0)
        {
            tmp += n % 10;
            n /= 10;
        }
        tmp += n;
        if (tmp / 10 != 0)
        {
            n = tmp;
            continue;
        }
        break;
    }

    return tmp;
}

int main(void)
{
    int n = -1;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << sum(n) << "\n";
    }
    return 0;
}