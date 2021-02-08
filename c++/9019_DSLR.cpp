/*
D : n의 값을 두배로 바꾼다. 값이 10000이상일 경우에는 10000을 나눈 나머지를 가진다.
S : n - 1을 저장하고 0이라면 9999로 바뀐다.
L : 왼쪽 쉬프트
R : 오른쪽 쉬프트

아직 문제를 보고 어떻게 풀면 되겠다는 확신이 들지 않는다.
알고리즘 분류를 보고 난 후 이런 방식으로 풀면 되구나를 깨닳고 난 후
문제를 푸는 단계.....ㅠ
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visit(10000);
queue<pair<int, string>> q;
int testcase, a, b;

int D(int n)
{
    if (2 * n > 9999)
        return 2 * n % 10000;
    else
        return 2 * n;
}

int S(int n)
{
    if (n == 0)
        return 9999;
    else
        return n - 1;
}

int L(int n)
{
    if (n * 10 > 9999)
        return (n * 10) % 10000 + (n * 10) / 10000;
    else
        return n * 10;
}

int R(int n)
{
    return (n / 10) + (n % 10 * 1000);
}

void solve()
{
    queue<pair<int, string>> tempQ;
    string temp;
    q.push(make_pair(a, temp));
    int d, s, l, r;
    while (!q.empty())
    {
        if (q.front().first == b)
        {
            cout << q.front().second << "\n";
            break;
        }
        d = D(q.front().first);
        s = S(q.front().first);
        l = L(q.front().first);
        r = R(q.front().first);
        temp = q.front().second;
        if (!visit[d])
        {
            temp.push_back('D');
            q.push(make_pair(d, temp));
            temp.pop_back();
            visit[d] = true;
        }
        if (!visit[s])
        {
            temp.push_back('S');
            q.push(make_pair(s, temp));
            temp.pop_back();
            visit[s] = true;
        }
        if (!visit[l])
        {
            temp.push_back('L');
            q.push(make_pair(l, temp));
            temp.pop_back();
            visit[l] = true;
        }
        if (!visit[r])
        {
            temp.push_back('R');
            q.push(make_pair(r, temp));
            temp.pop_back();
            visit[r] = true;
        }

        q.pop();
    }
    q.swap(tempQ);
    visit.assign(10000, false);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> a >> b;
        solve();
    }
    return 0;
}