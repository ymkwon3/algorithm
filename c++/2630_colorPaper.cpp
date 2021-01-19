#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> p;
int n;
int cntB = 0, cntW = 0;

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> element(n);
        p.push_back(element);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
}

void solve(int starti, int endi, int startj, int endj)
{
    int cmp = p[starti][startj];
    for (int i = starti; i < endi; i++)
    {
        for (int j = startj; j < endj; j++)
        {
            if (cmp != p[i][j])
            {
                solve(starti, (endi + starti) / 2, startj, (endj + startj) / 2);
                solve(starti, (endi + starti) / 2, (endj + startj) / 2, endj);
                solve((endi + starti) / 2, endi, startj, (endj + startj) / 2);
                solve((endi + starti) / 2, endi, (endj + startj) / 2, endj);
                return;
            }
        }
    }
    if (cmp == 0)
        cntW++;
    else
        cntB++;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve(0, n, 0, n);
    cout << cntW << "\n"
         << cntB << "\n";
    return 0;
}