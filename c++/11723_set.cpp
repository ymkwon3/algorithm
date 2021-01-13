/*
    명령어가 check일 때만 출력
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> v(21, 0);
int m;

void solve(string a)
{
    string tmp;
    string item;
    int index;
    bool space = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != ' ')
        {
            tmp.push_back(a[i]);
        }
        else
        {
            space = true;
            item = tmp;
            tmp.clear();
        }
    }
    if (space)
        index = stoi(tmp);
    else
        item = tmp;

    if (item.compare("add") == 0)
    {
        if (v[index] == 0)
            v[index] = 1;
    }
    else if (item.compare("remove") == 0)
    {
        if (v[index] == 1)
            v[index] = 0;
    }
    else if (item.compare("check") == 0)
    {
        cout << v[index] << "\n";
    }
    else if (item.compare("toggle") == 0)
    {
        if (v[index] == 0)
            v[index] = 1;
        else if (v[index] == 1)
            v[index] = 0;
    }
    else if (item.compare("all") == 0)
    {
        for (int i = 1; i < v.size(); i++)
        {
            v[i] = 1;
        }
    }
    else if (item.compare("empty") == 0)
    {
        for (int i = 1; i < v.size(); i++)
        {
            v[i] = 0;
        }
    }
}

void init()
{
    string a;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin, a);
        solve(a);
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