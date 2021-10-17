#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v, vector<int> e)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
        {
            if (e[i] + e[i + 1] != v[i])
                return true;
        }
        else
        {
            if (e[i] + e[0] != v[i])
                return true;
        }
    }
    return false;
}

int main(void)
{
    int n, input, pre;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n);
    ans[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v[i] = input;
        if (i != 0)
        {
            ans[i] = pre - ans[i - 1];
        }
        pre = input;
    }
    while (check(v, ans))
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                ans[i] = ans[i] + 1;
            else
                ans[i] = ans[i] - 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;
}