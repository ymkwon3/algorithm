/*
10,000,000개 수를 다 입력 받아서 저장하게 되면 8MB 메모리를 초과한다
입력되는 수의 범위가 작기 때문에 계수 정렬을 사용하는것이 좋음
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> s(10001, 0);
int n;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s[a]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i]; j++)
        {
            cout << i << "\n";
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