#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n;

void init()
{
    string a;
    int b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == "push")
        {
            cin >> b;
            q.push(b);
        }
        else if (a == "pop")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (a == "size")
        {
            cout << q.size() << "\n";
        }
        else if (a == "empty")
        {
            if (q.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (a == "front")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if (a == "back")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}