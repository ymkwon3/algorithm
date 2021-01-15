/*
the number of saved sites :  n
the number of sites looking for : m
used map
*/

#include <iostream>
#include <map>

using namespace std;
map<string, string> site;
int n, m;

void init()
{
    string s, p;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        site[s] = p;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (!site[s].empty())
        {
            cout << site[s] << "\n";
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}