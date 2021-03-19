#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[801];

int n, e;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    return 0;
}