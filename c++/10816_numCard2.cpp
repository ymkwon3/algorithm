#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
vector<int> m_input;
vector<int> plus_cards(10000001, 0);
vector<int> minus_cards(10000001, 0);
int n, m;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 0)
        {
            plus_cards[input[i]]++;
        }
        else if (input[i] < 0)
        {
            minus_cards[input[i]]++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        m_input.push_back(a);
    }
}

void solve()
{
    for (int i = 0; i < m_input.size(); i++)
    {
        if (m_input[i] >= 0)
        {
            cout << plus_cards[m_input[i]] << " ";
        }
        else if (m_input[i] < 0)
        {
            cout << minus_cards[m_input[i]] << " ";
        }
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