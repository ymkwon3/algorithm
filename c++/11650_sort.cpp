#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> input;
int n;

void init()
{
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        input.push_back(make_pair(a, b));
    }
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve()
{
    sort(input.begin(), input.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << input[i].first << " " << input[i].second << "\n";
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}