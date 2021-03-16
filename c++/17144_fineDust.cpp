#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

vector<int> ac;
int home[MAX][MAX];
int spread[MAX][MAX];
int r, c, t;

void spreading()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (home[i][j] >= 5)
            {
                int s = home[i][j] / 5;
                if (i - 1 > 0 && home[i - 1][j] != -1)
                {
                    spread[i - 1][j] += s;
                    home[i][j] -= s;
                }
                if (j + 1 <= c)
                {
                    spread[i][j + 1] += s;
                    home[i][j] -= s;
                }
                if (i + 1 <= r && home[i + 1][j] != -1)
                {
                    spread[i + 1][j] += s;
                    home[i][j] -= s;
                }
                if (j - 1 > 0 && home[i][j - 1] != -1)
                {
                    spread[i][j - 1] += s;
                    home[i][j] -= s;
                }
            }
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            home[i][j] += spread[i][j];
            spread[i][j] = 0;
        }
    }
}

void upCleaning()
{
    int start = ac[0];
    int tmp = 0, pre = 0;
    for (int j = 2; j <= c; j++)
    {
        tmp = home[start][j];
        home[start][j] = pre;
        pre = tmp;
    }
    start--;
    for (; start > 0; start--)
    {
        tmp = home[start][c];
        home[start][c] = pre;
        pre = tmp;
    }
    start++;
    for (int j = c - 1; j > 0; j--)
    {
        tmp = home[start][j];
        home[start][j] = pre;
        pre = tmp;
    }
    start++;
    for (; start <= ac[0]; start++)
    {
        if (start != ac[0])
        {
            tmp = home[start][1];
            home[start][1] = pre;
            pre = tmp;
        }
    }
}

void downCleaning()
{
    int start = ac[1];
    int tmp = 0, pre = 0;
    for (int j = 2; j <= c; j++)
    {
        tmp = home[start][j];
        home[start][j] = pre;
        pre = tmp;
    }
    start++;
    for (; start <= r; start++)
    {
        tmp = home[start][c];
        home[start][c] = pre;
        pre = tmp;
    }
    start--;
    for (int j = c - 1; j > 0; j--)
    {
        tmp = home[start][j];
        home[start][j] = pre;
        pre = tmp;
    }
    start--;
    for (; start >= ac[1]; start--)
    {
        if (start != ac[1])
        {
            tmp = home[start][1];
            home[start][1] = pre;
            pre = tmp;
        }
    }
}

void operating()
{
    spreading();
    upCleaning();
    downCleaning();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    int a;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> a;
            home[i][j] = a;
            if (a == -1)
                ac.push_back(i);
        }

    for (int i = 0; i < t; i++)
        operating();

    int sum = 0;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            if (home[i][j] != -1)
                sum += home[i][j];
        }
    cout << sum << "\n";

    return 0;
}