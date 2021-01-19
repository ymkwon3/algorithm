#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solve(vector<string> clothing, vector<int> cnt);

void init()
{
    int testcase;
    string c, k;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        vector<string> clothing;
        vector<int> cnt;
        cin >> n;
        if (n == 0)
        {
            cout << "0\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cin >> c >> k;
                clothing.push_back(k);
            }
            sort(clothing.begin(), clothing.end());
            solve(clothing, cnt);
        }
    }
}

void solve(vector<string> clothing, vector<int> cnt)
{
    int multiply = 1;
    string pre = clothing[0];
    cnt.push_back(count(clothing.begin(), clothing.end(), pre));
    for (int i = 1; i < n; i++)
    {
        if (pre != clothing[i])
        {
            pre = clothing[i];
            cnt.push_back(count(clothing.begin(), clothing.end(), pre));
        }
    }
    for (int i = 0; i < cnt.size(); i++)
    {
        multiply *= cnt[i] + 1;
    }

    cout << multiply - 1 << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}