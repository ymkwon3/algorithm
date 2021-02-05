/*
버튼 0~9, -, +
음수채널은 없고 양수로 무한대
현재채널 100
이동하고자하는채널 n
고장난버트의개수 m

처음에는 if문 엄청 넣으면서 n이 9990 일 경우 버튼이 고장나지 않은 최소의 값 최대의 값을 각각 넣어보며 최소로 비슷한값 최대로 비슷한값을 구해서
노가다로 했는데 결국 실패...

이 문제만 3일 걸렸다.....분발하자!
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> broken(10);
vector<int> num;
int n, m, channel = 100;
int result = 0;

int isPossible(int value)
{
    int test = value;
    int len = 0, sub = abs(value - n);
    int channelSub = abs(n - channel);
    if (value == 0)
    {
        len = 1;
        if (broken[0])
            return -1;
    }
    while (value)
    {
        if (broken[value % 10])
            return -1;
        value /= 10;
        len++;
    }
    return min(sub + len, channelSub);
}

int po(int a) // pow() 쓰니까 가끔 9999처럼 1 적은 상태로나와서 그냥 만듬...
{
    if (a == 0)
        return 10;
    int ans = 0;
    while (a)
    {
        a /= 10;
        ans++;
    }
    int ret = 1;
    for (int i = 0; i < ans + 1; i++)
    {
        ret *= 10;
    }
    return ret;
}

void solve()
{
    if (m == 10)
    {
        cout << abs(n - channel) << "\n";
        return;
    }
    int mini = -1;
    for (int i = 0; i <= po(n); i++)
    {
        int temp = isPossible(i);
        if (mini == -1 && temp != -1)
            mini = temp;
        else if (temp != -1 && temp < mini)
            mini = temp;
    }
    cout << mini << "\n";
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
        broken[a] = true;
    }
    solve();
    return 0;
}