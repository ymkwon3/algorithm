#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n, m, input;
    int ansA = 0, ansB = 0;
    vector<int> p;
    cin >> n >> m;
    vector<pair<int, int>> price(m);

    for (int i = 0; i < m; i++)
    {
        cin >> input;
        p.push_back(input);
    }
    sort(p.begin(), p.end(), greater<int>());
    for (int i = n - 1; i >= 0; i--)
    {
        price[i].first = p[i] * (i + 1);
        price[i].second = p[i];
    }
    for (auto a : price)
    {
        if (ansA < a.first)
        {
            ansA = a.first;
            ansB = a.second;
        }
    }
    cout << ansB << " " << ansA << "\n";
    return 0;
}