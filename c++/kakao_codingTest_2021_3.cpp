#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
vector<bool> view;

int count(int start, int end, int k)
{
    int tmp = 0;
    for (int i = start; i <= end; i++)
    {
        if (!view[i] && i != k)
            tmp++;
    }
    return tmp;
}

int move(int k, int cnt, char c)
{
    cout << "k cnt c : " << k << cnt << c << "\n";
    if (c == 'U')
    {
        k = k - cnt - count(k - cnt, k, k);
        cout << k << " :q " << count(k - cnt, k, k) << "\n";
    }
    else if (c == 'D')
    {
        k = k + cnt + count(k, k + cnt, k);
        cout << k << " :w " << count(k, k + cnt, k) << "\n";
    }
    return k;
}

int last(int n)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        if (view[i])
            tmp = i;
    }
    return tmp;
}

int num(string s)
{
    int tmp = 0;
    for (int i = 2; i < s.size(); i++)
    {
        tmp *= 10;
        tmp += s[i] - '0';
    }
    return tmp;
}

int main(void)
{
    int n = 8; // 행 크기
    int k = 2; // 선택 위치
    vector<string> cmd = {"C" , "C", "U 1"};
    for (int i = 0; i < n; i++)
        view.push_back(true);

    stack<int> del;
    int l = n - 1;
    for (int i = 0; i < cmd.size(); i++)
    {
        if (!view[l])
        {
            l = last(n);
        }
        if (cmd[i][0] == 'U')
            k = move(k, num(cmd[i]), 'U');
        else if (cmd[i][0] == 'D')
            k = move(k, num(cmd[i]), 'D');
        else if (cmd[i][0] == 'C')
        {
            if (k == l)
            {
                view[k] = false;
                del.push(k);
                k = move(k, 1, 'U');
            }
            else
            {
                view[k] = false;
                del.push(k);
                k = move(k, 1, 'D');
            }
        }
        else if (cmd[i][0] == 'Z')
        {
            cout << del.top() << "\n";
            view[del.top()] = true;
            del.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (view[i])
            cout << 'O';
        else
            cout << 'X';
    }
    return 0;
}