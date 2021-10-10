#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<char, int> &a, pair<char, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    string input, answer = "";
    int ansNum = 0;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < m; i++)
    {
        map<char, int> DNA;
        for (int j = 0; j < n; j++)
        {
            DNA[v[j][i]]++;
        }
        vector<pair<char, int>> vec(DNA.begin(), DNA.end());
        sort(vec.begin(), vec.end(), cmp);
        answer += vec[0].first;
        ansNum += (n - vec[0].second);
    }
    cout << answer << "\n";
    cout << ansNum << "\n";
    return 0;
}