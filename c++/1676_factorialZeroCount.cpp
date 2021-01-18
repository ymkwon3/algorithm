#include <iostream>
#include <vector>

using namespace std;

int n;

void init()
{
    cin >> n;
}

void solve()
{
    int tmp, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp = i;
        if (tmp % 5 == 0)
        {
            while (true)
            {
                if (tmp % 5 == 0)
                {
                    tmp /= 5;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}