#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    long long n, ans = 0;
    cin >> n;
    vector<int> v;
    while (n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int a : v)
    {
        ans *= 10;
        ans += a;
    }

    cout << ans << "\n";

    return 0;
}