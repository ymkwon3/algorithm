#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> a;
vector<int> b;
int n, m;

int commonMeasure();
int commonMultiple();

void init()
{
    cin >> n >> m;
    if (n == m)
    {
        cout << n << "\n"
             << n << "\n";
    }
    else
    {
        cout << commonMeasure() << "\n";
        cout << commonMultiple() << "\n";
    }
}

int commonMeasure() // 최대공약수
{
    for (int i = 1; i <= n; i++)
    {
        if ((n / i) * i == n)
        {
            a.push_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if ((m / i) * i == m)
        {
            b.push_back(i);
        }
    }
    while (a.size() != 0)
    {
        for (int i = b.size() - 1; i > 0; i--)
        {
            if (a[a.size() - 1] == b[i])
            {
                return a[a.size() - 1];
            }
        }
        a.pop_back();
    }
    return 1;
}

int commonMultiple()
{
    int small, big;
    int sum_s, sum_b;
    if (n < m)
    {
        small = n;
        big = m;
    }
    else
    {
        small = m;
        big = n;
    }

    sum_s = small;
    sum_b = big;

    while (true)
    {
        if (sum_s == sum_b)
        {
            return sum_s;
        }
        if (abs(sum_b - sum_s) < big)
        {
            sum_s += small;
        }
        else
        {
            sum_b += big;
        }
    }
    return 0;
}

int main(void)
{
    init();
    return 0;
}