#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> words;

void init()
{
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        words.push_back(s);
    }
}

bool comp(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

void solve()
{
    stable_sort(words.begin(), words.end(), comp);

    string pre = "";
    for (int i = 0; i < words.size(); i++)
    {
        if (pre == words[i])
            continue;
        cout << words[i] << "\n";
        pre = words[i];
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}