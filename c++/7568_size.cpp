#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> input;
int n;

void init()
{
    int h, w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> h;
        input.push_back(make_pair(w, h));
    }
}

void solve()
{
    int rank;
    for (int i = 0; i < n; i++)
    {
        rank = 1;
        for (int j = 0; j < n; j++)
        {
            if (input[i].first < input[j].first && input[i].second < input[j].second)
                rank++;
        }
        cout << rank << " ";
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