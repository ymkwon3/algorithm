#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> calendar;
int t, m, n, x, y;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void cal()
{
    int l = lcm(m, n);
    // for (int i = 1; i <= l; i++) // time over
    // {
    //     if (i == l && (m != x || n != y))
    //     {
    //         cout << "-1\n";
    //         break;
    //     }
    //     if (i % m * y == i % n * x)
    //     {
    //         cout << i << "\n";
    //         break;
    //     }
    // }
    int i = 0;
    int a = 0, b = 0;
    while (i < l)
    {
        if (i < x)
        {
            i++;
            a++;
            if (b < n)
                b++;
            else
                b = 1;
        }
        else
        {
            i += m;
            b = (b + m) % n;
            if (b == 0)
                b = n;
        }
        if (a == x && b == y)
            break;
    }
    if (a == x && b == y)
        cout << i << "\n";
    else
        cout << "-1\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> x >> y;
        cal();
    }
    return 0;
}