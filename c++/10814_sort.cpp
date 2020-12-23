#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, string>> input;
int n;

void init()
{
    int age;
    string name;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        input.push_back(make_pair(age, name));
    }
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

void solve()
{
    stable_sort(input.begin(), input.end(), cmp);
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