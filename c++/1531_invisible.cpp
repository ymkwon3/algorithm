#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
void blind(int x1, int x2, int y1, int y2)
{
    for (int i = x2; i <= y2; i++)
        for (int j = x1; j <= y1; j++)
            arr[i][j]++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int x1, x2, y1, y2;

    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> x2 >> y1 >> y2;
        blind(x1, x2, y1, y2);
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (arr[i][j] > m)
                cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}