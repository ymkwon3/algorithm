#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;
void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(a);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    return 0;
}