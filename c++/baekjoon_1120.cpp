#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int ans = 999;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= b.size() - a.size(); i++)
    {
        int diff = 0;
        for (int j = i, k = 0; j < a.size() + i; j++, k++)
        {
            if (b[j] != a[k])
                diff++;
        }
        ans = ans > diff ? diff : ans;
    }
    cout << ans << "\n";
    return 0;
}