#include <iostream>

using namespace std;

int t;       // 테스트 케이스 수
int h, w, n; // 층 수, 방 수, 몇번째 손님

void solve();

void init()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        solve();
    }
}

void solve()
{
    int floor, number, fn;
    if (n % h == 0)
    {
        cout << h * 100 + n / h << "\n";
        return;
    }

    floor = n % h;
    number = 1 + (n / h);
    fn = floor * 100 + number;
    cout << fn << "\n";
    return;
}

int main(void)
{
    init();
    return 0;
}