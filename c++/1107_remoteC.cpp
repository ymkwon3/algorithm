/*
버튼 0~9, -, +
음수채널은 없고 양수로 무한대
현재채널 100
이동하고자하는채널 n
고장난버트의개수 m
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> x(10, 1);
vector<int> num;
int n, m, vs = 10, vb = -1, channel = 100; // vs : 조작 가능한 버튼중 가장 작은 수, vb : 조작 가능한 버튼중 가장 큰 수
int result = 0;

int digitLen(int len)
{
    if (len == 0)
        return 1;
    int ans = 0;
    while (len)
    {
        len /= 10;
        ans++;
    }
    return ans;
}

void setNum()
{
    int temp = n;
    if (temp == 0)
    {
        num.push_back(0);
    }
    while (temp != 0)
    {
        num.push_back(temp % 10);
        temp /= 10;
    }
}

int po(int a)
{
    if (a == 0)
        return 1;
    int ret = 1;
    for (int i = 0; i < a; i++)
    {
        ret *= 10;
    }
    return ret;
}

int cmpBigger()
{
    int tmp = 0;
    int number;
    bool change = false;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        number = 10;
        if (!change)
        {
            for (int j = 9; j >= num[i]; j--)
            {
                if (i == num.size() - 1 && num[i] == 9)
                {
                    number = vs;
                    if (vs == 0)
                        tmp += (vs + 1) * po(i + 1);
                    else
                        tmp += vs * po(i + 1);
                }
                else if (num[i] == 9)
                {
                    number = vs;
                    if (x[(tmp / po(i + 1)) + 1])
                        tmp += po(i + 1);
                }
                if (x[j] && number >= j)
                    number = j;
            }
            if (number != num[i])
                change = true;
            if (number != 10)
                tmp += number * po(i);
        }
        else
        {
            tmp += vs * po(i);
        }
        cout << "tmpB :: " << tmp << "\n";
    }
    return tmp;
}

int cmpSmaller()
{
    int tmp = 0;
    int number;
    bool change = false;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        number = -1;
        if (!change)
        {
            for (int j = 0; j <= num[i]; j++)
            {
                if (num[i] == 0)
                {
                    number = vb;
                    if (x[(tmp / po(i + 1)) - 1] || tmp / po(i + 1) - 1 == 0)
                        tmp -= po(i + 1);
                }
                if (x[j] && number <= j)
                    number = j;
            }
            if (number != num[i])
                change = true;
            if (number != -1)
                tmp += number * po(i);
        }
        else
        {
            tmp += vb * po(i);
        }
        cout << "tmpS :: " << tmp << "\n";
    }
    return tmp;
}

void solve()
{
    int big, small, sub, bans, sans;
    if (n == channel)
    {
        cout << 0 << "\n";
        return;
    }
    else if (m == 10)
    {
        cout << abs(channel - n) << "\n";
        return;
    }
    else if (n == 0)
    {
        if (!x[0])
            cout << vs + 1 << "\n";
        else
            cout << 1 << "\n";
        return;
    }

    big = cmpBigger();
    small = cmpSmaller();
    sub = abs(100 - n);
    bans = abs(n - big) + digitLen(big);
    sans = abs(n - small) + digitLen(small);
    if (big == 0)
    {
        cout << min(sans, sub) << "\n";
        return;
    }
    else if (small == 0)
    {
        cout << min(bans, sub) << "\n";
        return;
    }
    else
        cout << min(min(bans, sans), sub) << "\n";
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        x[a] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (x[i] == 1)
        {
            if (i < vs)
                vs = i;
            if (i > vb)
                vb = i;
        }
    }
    setNum();
    solve();
    return 0;
}