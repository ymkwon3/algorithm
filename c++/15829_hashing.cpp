#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int M = 1234567891;
const int MULTIPLY = 31;

int l;
vector<char> input;

void init()
{
    char c;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> c;
        input.push_back(c);
    }
}

void solve()
{
    long long sum = 0;
    long long r = 1;
    for (int i = 0; i < l; i++)
    {
        sum = (sum + (int(input[i]) - 96) * r) % M;
        r = (r * MULTIPLY) % M;
    }
    cout << sum << "\n";
    // long long hash = 0;
    // for (int i = 0; i < l; i++)
    // {
    //     hash += ((int(input[i]) - 96) * pow(31, i));
    // }
    // cout << hash << "\n";
}

int main(void)
{
    init();
    solve();
    return 0;
}