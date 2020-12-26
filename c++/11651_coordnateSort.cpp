#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> input;
int n;

void init()
{
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        input.push_back(make_pair(x, y));
    }
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve()
{
    sort(input.begin(), input.end(), cmp);
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i].first << " " << input[i].second << "\n";
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