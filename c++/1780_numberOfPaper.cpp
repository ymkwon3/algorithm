#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
int minusOne = 0, zero = 0, one = 0, n;

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> element(n);
        v.push_back(element);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
}

void solve(int rowS, int rowE, int colS, int colE)
{
    int f = v[rowS][colS];
    for (int i = rowS; i < rowE; i++)
    {
        for (int j = colS; j < colE; j++)
        {
            if (f != v[i][j])
            {
                solve(rowS, (rowE - rowS) / 3 + rowS, colS, (colE - colS) / 3 + colS);
                solve(rowS, (rowE - rowS) / 3 + rowS, (colE - colS) / 3 + colS, (colE - colS) / 3 * 2 + colS);
                solve(rowS, (rowE - rowS) / 3 + rowS, (colE - colS) / 3 * 2 + colS, colE);
                solve((rowE - rowS) / 3 + rowS, (rowE - rowS) / 3 * 2 + rowS, colS, (colE - colS) / 3 + colS);
                solve((rowE - rowS) / 3 + rowS, (rowE - rowS) / 3 * 2 + rowS, (colE - colS) / 3 + colS, (colE - colS) / 3 * 2 + colS);
                solve((rowE - rowS) / 3 + rowS, (rowE - rowS) / 3 * 2 + rowS, (colE - colS) / 3 * 2 + colS, colE);
                solve((rowE - rowS) / 3 * 2 + rowS, rowE, colS, (colE - colS) / 3 + colS);
                solve((rowE - rowS) / 3 * 2 + rowS, rowE, (colE - colS) / 3 + colS, (colE - colS) / 3 * 2 + colS);
                solve((rowE - rowS) / 3 * 2 + rowS, rowE, (colE - colS) / 3 * 2 + colS, colE);
                return;
            }
        }
    }
    if (f == -1)
        minusOne++;
    else if (f == 0)
        zero++;
    else if (f == 1)
        one++;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve(0, n, 0, n);
    cout << minusOne << "\n";
    cout << zero << "\n";
    cout << one << "\n";
    return 0;
}