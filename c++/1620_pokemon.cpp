#include <iostream>
#include <map>
using namespace std;

map<string, string> name;
map<string, string> num;
int n, m;

void init()
{
    string a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        name[a] = to_string(i);
        num[to_string(i)] = a;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (!name[a].empty())
            cout << name[a] << "\n";
        else
            cout << num[a] << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    return 0;
}