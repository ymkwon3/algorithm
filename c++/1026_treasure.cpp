#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; i++)
        ans += a[i] * b[i];

    cout << ans << "\n";
    return 0;
}