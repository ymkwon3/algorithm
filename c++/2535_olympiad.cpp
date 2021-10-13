#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    vector<pair<int, pair<int, int>>> v;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 0; i < n; i++)
    {
        int c, num, s;
        cin >> c >> num >> s;
        v.push_back({s, {c, num}});
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1, j = 0; i >= 0; i--)
    {
        if (t[v[i].second.first] < 2)
        {
            t[v[i].second.first]++;
            cout << v[i].second.first << " " << v[i].second.second << "\n";
            j++;
            if (j == 3)
                break;
        }
    }
    return 0;
}