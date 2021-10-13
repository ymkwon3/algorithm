#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int l, n, tmp;
    int min = 0, max = 1001, ans = 0;
    vector<int> s;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> tmp;
        s.push_back(tmp);
    }
    cin >> n;

    for (int i : s)
    { // 집합안에서 기준값에 가장 근접하게 작고 큰 값 구하기
        if (i == n)
        {
            cout << 0 << "\n";
            return 0;
        }
        else if (i < n && i > min)
            min = i;
        else if (i > n && i < max)
            max = i;
    }
    if (max - min == 2) // 이 경우 집합에서 A < B를 만족시키지 못하기 때문에 제외
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << min << " " << max << "\n";
    max--;
    min++;
    while (min <= n)
    {
        ans += max - min;
        if (n - min != 0)
            ans -= (n - min) - 1;
        min++;
    }

    cout << ans << "\n";
    return 0;
}