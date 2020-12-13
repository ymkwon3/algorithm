#include <iostream>

using namespace std;

int a, b, v;
int sum = 0, cnt = 0;

void init()
{
    cin >> a >> b >> v;
}

void solve()
{
    int i = 0, q = 0, r = 0;
    if (a == v)
    {
        cout << 1 << "\n";
        return;
    }
    i = v - a;
    q = i / (a - b);
    r = i % (a - b);
    if (q == 0)
    {
        cout << 2 << "\n";
        return;
    }
    if (r > 0)
    {
        cout << q + 2 << "\n";
        return;
    }
    cout << q + 1 << "\n";
}

// void solve() //시간초과
// {
//     while (true)
//     {
//         sum += a;
//         if (sum > v)
//         {
//             cout << cnt << "\n";
//             break;
//         }
//         sum -= b;
//         cnt++;
//     }
// }

int main(void)
{
    init();
    solve();
    return 0;
}