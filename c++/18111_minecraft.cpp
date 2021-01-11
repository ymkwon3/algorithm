#include <iostream>
#include <vector>

using namespace std;

vector<int> area;
int n, m, b;
int maximum = 0;
int minimum = 1e9;
int time = 1e9;
int high = 0;
void init()
{
    int height;
    cin >> n >> m >> b;

    for (int i = 0; i < n * m; i++)
    {
        cin >> height;
        area.push_back(height);
        if (height > maximum)
            maximum = height;
        else if (height < minimum)
            minimum = height;
    }
}

void ExhaustiveSearch(int height)
{
    int t = 0;
    int inven = b;
    for (int i = 0; i < n * m; i++)
    {
        if (area[i] > height)
        {
            t += (area[i] - height) * 2;
            inven += area[i] - height;
        }
        else if (area[i] < height)
        {
            t += height - area[i];
            inven -= height - area[i];
        }
    }
    if (inven >= 0)
    {
        if (t < time)
        {
            high = height;
            time = t;
        }
        else if (t == time)
        {
            if (high < height)
            {
                high = height;
            }
        }
    }
}

void solve()
{
    for (int i = minimum; i <= maximum; i++)
    {
        ExhaustiveSearch(i);
    }

    cout << time << " " << high << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}