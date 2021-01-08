#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> area;
vector<int> h(257, 0);
int n, m, b;
int many;
int time = 0;
void init()
{
    int height;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
    {
        vector<int> element(m, 0);
        area.push_back(element);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> height;
            area[i][j] = height;
            h[height]++;
        }
    }
    many = max_element(h.begin(), h.end()) - h.begin();
}

int fillUp(vector<vector<int>> a)
{
    int inven = b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != many)
            {
                inven += a[i][j] - many;
                a[i][j] += a[i][j] - many;
                time++;
            }
        }
    }
    return inven;
}

void solve()
{
    if (fillUp(area) < 0)
    {
        time = 0;
        // 인벤에 여분이 없고 더 쪼개야할 때를 해야함
    }
    else
    {
        cout << many << " " << time << "\n";
    }
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