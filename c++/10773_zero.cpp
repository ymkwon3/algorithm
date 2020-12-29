#include <iostream>
#include <vector>

using namespace std;

void solve();

vector<int> input;
int n;

void init()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        solve();
    }
    for (int i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }
    cout << sum << "\n";
}

void solve()
{
    int a;
    cin >> a;
    if (a == 0)
    {
        input.pop_back();
    }
    else
    {
        input.push_back(a);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}