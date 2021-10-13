#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> tmp(30);
    vector<vector<int>> v(30, tmp);

    for (int i = 0; i < v[0].size(); i++)
        v[0][i] = i + 1;
    for (int i = 1; i < v[0].size(); i++)
    {
        for (int j = i; j < v[0].size(); j++)
        {
            v[i][j] = v[i][j - 1] + v[i - 1][j - 1];
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int left, right;
        cin >> left >> right;

        cout << v[left - 1][right - 1] << "\n";
    }

    return 0;
}