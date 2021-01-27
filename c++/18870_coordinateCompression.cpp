#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> m;
vector<int> xs;
vector<int> xsTmp;
int n, x;

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        xs.push_back(x);
        xsTmp.push_back(x);
    }
    sort(xsTmp.begin(), xsTmp.end());
}

void solve()
{
    int pre = xsTmp[0], index = 0;
    m.insert(make_pair(pre, index));
    for (int i = 1; i < n; i++)
    {
        if (pre != xsTmp[i])
        {
            index++;
            pre = xsTmp[i];
            m.insert(make_pair(pre, index));
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << m[xs[i]] << " ";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();
    return 0;
}