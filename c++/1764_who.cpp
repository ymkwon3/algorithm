#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> listen;
vector<string> see;
vector<string> result;
int n, m;

void init()
{
    string a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        listen.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        see.push_back(a);
    }
    sort(listen.begin(), listen.end());
    sort(see.begin(), see.end());
}

void solve()
{
    int left;
    int right;
    int pivot;
    int cmp;
    for (int i = 0; i < see.size(); i++)
    {
        left = 0;
        right = listen.size() - 1;
        while (left <= right)
        {
            pivot = (left + right) / 2;
            cmp = see[i].compare(listen[pivot]);
            if (cmp == 0)
            {
                result.push_back(see[i]);
                break;
            }
            else if (cmp < 0)
            {
                right = pivot - 1;
            }
            else if (cmp > 0)
            {
                left = pivot + 1;
            }
        }
    }
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
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