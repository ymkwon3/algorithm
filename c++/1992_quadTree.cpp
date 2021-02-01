//    a   b
//   c
//   d

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
int n;

void quadTree(int a, int b, int c, int d)
{
    int first = v[c][a];
    bool w = false;
    for (int i = c; i < d; i++)
    {
        for (int j = a; j < b; j++)
        {
            if (v[i][j] != first)
            {
                w = true;
                cout << "(";
                quadTree(a, (a + b) / 2, c, (c + d) / 2);
                quadTree((a + b) / 2, b, c, (c + d) / 2);
                quadTree(a, (a + b) / 2, (c + d) / 2, d);
                quadTree((a + b) / 2, b, (c + d) / 2, d);
                cout << ")";
                return;
            }
        }
    }
    if (!w)
        cout << first;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> e(n);
        v.push_back(e);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%1d", &v[i][j]);
    }
    quadTree(0, n, 0, n);
    return 0;
}