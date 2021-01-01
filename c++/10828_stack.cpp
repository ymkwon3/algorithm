#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
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
            s.push(b);
        }
        else if (a == "pop")
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (a == "top")
        {
            if (s.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s.top() << "\n";
            }
        }
        else if (a == "size")
        {
            cout << s.size() << "\n";
        }
        else if (a == "empty")
        {
            if (s.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}