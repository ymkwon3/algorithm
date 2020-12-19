#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> input;
int n;

void init()
{
    cin >> n;
    for (int i = 0, v = 0; i < n; i++)
    {
        cin >> v;
        input.push_back(v);
    }
}

void solve()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sort(input.begin(), input.end());
    input.erase(unique(input.begin(), input.end()), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << "\n";
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}