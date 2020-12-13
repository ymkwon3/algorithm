#include <iostream>
#include <vector>
using namespace std;

vector<int> input;
int n, m;
int sum = 0;

void init()
{
    cin >> n >> m;
    for (int i = 0, a = 0; i < n; i++)
    {
        cin >> a;
        input.push_back(a);
    }
}

void solve()
{
    int max = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = input[i] + input[j] + input[k];
                if (sum == m)
                {
                    cout << sum << "\n";
                    return;
                }
                if (max < sum && sum <= m)
                    max = sum;
            }
        }
    }
    cout << max << "\n";
}

int main(void)
{
    init();
    solve();
    return 0;
}