#include <iostream>
#include <vector>
using namespace std;

vector<int> input;
int n;

void init()
{
    int number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        input.push_back(number);
    }
}

void solve()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 1)
            continue;

        if (input[i] == 2 || input[i] == 5)
        {
            cnt++;
            continue;
        }

        if (input[i] % 10 == 1 || input[i] % 10 == 3 || input[i] % 10 == 7 || input[i] % 10 == 9)
        {
            for (int j = 2; j <= input[i]; j++)
            {
                if (j == input[i])
                    cnt++;
                if (input[i] / j * j == input[i])
                    break;
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