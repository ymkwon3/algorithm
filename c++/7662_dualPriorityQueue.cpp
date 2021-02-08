#include <iostream>
#include <map>
using namespace std;
map<long long, long long> Q;
int t, k;

void input(char a, long long b)
{
    if (a == 'I')
        Q[b]++;
    else if (a == 'D')
    {
        if (!Q.empty())
        {
            if (b == 1)
            {
                Q[Q.rbegin()->first]--;
                if (Q[Q.rbegin()->first] == 0)
                    Q.erase(Q.rbegin()->first);
            }
            else if (b == -1)
            {
                Q[Q.begin()->first]--;
                if (Q[Q.begin()->first] == 0)
                    Q.erase(Q.begin()->first);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a;
    long long b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> a >> b;
            input(a, b);
        }
        if (Q.empty())
            cout << "EMPTY\n";
        else
            cout << Q.rbegin()->first << " " << Q.begin()->first << "\n";
        Q.clear();
    }

    return 0;
}