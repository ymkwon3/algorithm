#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;
int n, k;

void sum()
{
    int index, num = 0;
    for (int i = 0; i < n; i++)
    {
        if (coin[i] > k)
        {
            index = i - 1;
            break;
        }
        else if (i == n - 1)
            index = i;
    }
    while (k != 0)
    {
        if (k / coin[index] > 0)
        {
            num += k / coin[index];
            k = k % coin[index];
        }
        index--;
    }
    cout << num << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        coin.push_back(a);
    }
    sum();
    return 0;
}