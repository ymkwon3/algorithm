#include <iostream>

using namespace std;

int n, m;
string s;

void init()
{
    cin >> n >> m >> s;
}

void solve()
{
    int k;
    int count = 0;
    for (int i = 0; i <= m - (2 * n + 1); i++)
    {
        if (s[i] == 'O')
            continue;
        else
        {
            k = 0;

            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                k++;
                if (k == n)
                {
                    k--;
                    count++;
                }
                i += 2;
            }
        }
    }
    cout << count << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();
    return 0;
}