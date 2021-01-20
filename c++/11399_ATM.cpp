#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> p;
int n;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void init()
{
    int a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        p.push_back(make_pair(i, a));
    }
    sort(p.begin(), p.end(), cmp);
}

void solve()
{
    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i].second;
        result += sum;
    }

    cout << result << "\n";
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