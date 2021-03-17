#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

vector<vector<int>> v(MAX);
vector<vector<int>> p(MAX);
vector<int> trueN;
int party[MAX];

int n, m, tn;

void func1(int index);
void func2(int index);

void func1(int index)
{
    for (int i = 0; i < v[index].size(); i++)
    {
        if (party[v[index][i]] != 1)
            func2(v[index][i]);
    }
}

void func2(int index)
{
    party[index] = 1;
    for (int i = 0; i < p[index].size(); i++)
    {
        func1(p[index][i]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;

    cin >> n >> m;
    cin >> tn;
    for (int i = 0; i < tn; i++)
    {
        cin >> a;
        trueN.push_back(a);
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            v[b].push_back(i);
            p[i].push_back(b);
        }
        if (a == 0)
            party[i] = 1;
    }

    for (int i = 0; i < tn; i++)
    {
        func1(trueN[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if (party[i] == 0)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}