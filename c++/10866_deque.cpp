#include <iostream>
#include <deque>

using namespace std;

deque<int> d;
int n;

void init()
{
    string a;
    int b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == "push_front")
        {
            cin >> b;
            d.push_front(b);
        }
        else if (a == "push_back")
        {
            cin >> b;
            d.push_back(b);
        }
        else if (a == "pop_front")
        {
            if (d.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if (a == "pop_back")
        {
            if (d.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if (a == "size")
        {
            cout << d.size() << "\n";
        }
        else if (a == "empty")
        {
            if (d.empty())
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
            if (d.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << d.front() << "\n";
            }
        }
        else if (a == "back")
        {
            if (d.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << d.back() << "\n";
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