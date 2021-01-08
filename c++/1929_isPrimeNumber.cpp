#include <iostream>
#include <vector>
using namespace std;

vector<bool> v(1000001, true);
int n, m;

void init()
{
    v[1] = false;
    for (int i = 2; i < 1000001; i++)
    {
        if (v[i])
        {
            for (int j = i; j <= 1000001; j += i)
            {
                if (j != i)
                    v[j] = false;
            }
        }
    }
    cin >> n >> m;
}

void solve()
{
    for (int i = n; i <= m; i++)
    {
        if (v[i])
            cout << i << "\n";
    }
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