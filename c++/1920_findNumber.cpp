#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> inputN;
vector<int> inputM;
int n, m;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        inputN.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        inputM.push_back(a);
    }
}

void recursive(int value, int begin, int end)
{
    if (begin > end)
    {
        cout << "0\n";
        return;
    }
    int pivot;
    pivot = (begin + end) / 2;
    if (value < inputN[pivot])
    {
        return recursive(value, begin, pivot - 1);
    }
    else if (value > inputN[pivot])
    {
        return recursive(value, pivot + 1, end);
    }
    else if (value == inputN[pivot])
    {
        cout << "1\n";
        return;
    }
}

void solve()
{
    sort(inputN.begin(), inputN.end());
    for (int i = 0; i < m; i++)
    {
        recursive(inputM[i], 0, n - 1);
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}