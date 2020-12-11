#include <iostream>
using namespace std;

int x, y, w, h;
int minX, minY;

void init()
{
    cin >> x >> y >> w >> h;
}

void solve()
{
    if (x <= w / 2)
    {
        minX = x;
    }
    else if (x > w / 2)
    {
        minX = w - x;
    }
    if (y <= h / 2)
    {
        minY = y;
    }
    else if (y > h / 2)
    {
        minY = h - y;
    }
    if (minX > minY)
    {
        cout << minY << "\n";
    }
    else
    {
        cout << minX << "\n";
    }
}

int main(void)
{
    init();
    solve();
    return 0;
}