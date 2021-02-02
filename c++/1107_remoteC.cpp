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
void setNum()
{
    int temp = n;
    while (temp != 0)
    {
        num.push_back(temp % 10);
        temp /= 10;
    }
}

void cmpBigger(int index)
{
    int tmp = result;
    bool change = false;
    for (int i = index; i >= 0; i--)
    {
        int j = 1;
        if (!change)
        {
            while (true)
            {
                if (num[i + j])
                {
                    result += num[i + j] * pow(10, i);
                    break;
                }
                j++;
            }
        }
        else
        {
        }
    }
}

void cmpSmaller(int index)
{
    for (int i = index; i >= 0; i--)
    {
    }
}

void solve()
{
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
        cout << vs + 1 << "\n";
        return;
    }
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (x[num[i]])
        {
            result += num[i] * pow(10, i);
        }
        else
        {
            cmpBigger(i);
            cmpSmaller(i);
            break;
        }
    }
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