#include <iostream>
#include <vector>

using namespace std;
vector<char> balance;
string p;
int n;

void solve();

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        solve();
    }
}

void solve()
{
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(' || p[i] == '[')
        {
            balance.push_back(p[i]);
        }
        else if (p[i] == ')' || p[i] == ']')
        {
            balance.push_back(p[i]);
            if (balance.size() > 1)
            {
                if (balance[balance.size() - 2] == '(' && balance[balance.size() - 1] == ')')
                {
                    balance.pop_back();
                    balance.pop_back();
                }
                else if (balance[balance.size() - 2] == '[' && balance[balance.size() - 1] == ']')
                {
                    balance.pop_back();
                    balance.pop_back();
                }
            }
        }
    }
    if (balance.size() == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    p.clear();
    balance.clear();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}