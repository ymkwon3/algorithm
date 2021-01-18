#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> network;
vector<bool> infected(101, false);
int n, m;
int a, b;

void init()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        network.push_back(make_pair(a, b));
    }
    sort(network.begin(), network.end());
}

void solve()
{
    int cnt = 0;
    bool c = true;
    infected[1] = true;
    while (c)
    {
        c = false;
        for (int i = 0; i < m; i++)
        {
            if (infected[network[i].first] && !infected[network[i].second])
            {
                infected[network[i].second] = true;
                c = true;
                cnt++;
            }
            else if (infected[network[i].second] && !infected[network[i].first])
            {
                infected[network[i].first] = true;
                c = true;
                cnt++;
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