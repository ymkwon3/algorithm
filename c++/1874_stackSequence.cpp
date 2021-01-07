#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> seq;
vector<char> result;
stack<int> s;
int n;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        seq.push_back(a);
    }
}

void solve()
{
    int i = 0;
    int j = 1;
    while (true)
    {
        if (!s.empty() && s.top() == seq[i])
        {
            s.pop();
            result.push_back('-');
            i++;
        }
        else
        {
            if (j <= n)
            {
                s.push(j);
                result.push_back('+');
            }
            else if (j > n && !s.empty())
            {
                cout << "NO\n";
                break;
            }
            j++;
        }
        if (j > n && s.empty())
        {
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << "\n";
            }
            break;
        }
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