#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> input(3);

void init()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}

void solve()
{
    while (true)
    {
        init();
        if (input[0] == 0 && input[1] == 0 && input[2] == 0)
            break;
        if (input[2] * input[2] == input[0] * input[0] + input[1] * input[1])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}

int main(void)
{
    solve();
    return 0;
}