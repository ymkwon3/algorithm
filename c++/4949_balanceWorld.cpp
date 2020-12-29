#include <iostream>
#include <vector>

using namespace std;

vector<char> balance;
string n;
void solve();

void init()
{
    while (true)
    {
        getline(cin, n);
        if (n == ".")
            break;
        solve();
    }
}

void solve()
{
    balance.clear();
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '(' || n[i] == '[')
        {
            balance.push_back(n[i]);
        }
        else if (n[i] == ')' || n[i] == ']')
        {
            balance.push_back(n[i]);
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
        cout << "yes\n";
    else
        cout << "no\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}