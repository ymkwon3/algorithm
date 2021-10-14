#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, i = 0, j = 0;
    int t, x, y;
    cin >> n;
    cin >> t;
    int value = n * n;
    vector<int> tmp(n);
    vector<vector<int>> v(n, tmp);
    while (true)
    {
        while (true)
        {
            if (i < n && v[i][j] == 0)
            {
                v[i][j] = value--;
                i++;
            }
            else
            {
                i--, j++;
                break;
            }
        }
        while (true)
        {
            if (j < n && v[i][j] == 0)
            {
                v[i][j] = value--;
                j++;
            }
            else
            {
                j--, i--;
                break;
            }
        }
        while (true)
        {
            if (i >= 0 && v[i][j] == 0)
            {
                v[i][j] = value--;
                i--;
            }
            else
            {
                i++, j--;
                break;
            }
        }
        while (true)
        {
            if (j >= 0 && v[i][j] == 0)
            {
                v[i][j] = value--;
                j--;
            }
            else
            {
                j++, i++;
                break;
            }
        }
        if (v[i][j] != 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
            if (v[i][j] == t)
            {
                x = i + 1, y = j + 1;
            }
        }
        cout << "\n";
    }
    cout << x << " " << y << "\n";
    return 0;
}