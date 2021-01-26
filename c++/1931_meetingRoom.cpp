/*
1개의 회의실, n개의 회의, 최대 회의 출력
회의 시작시간과 종료시간이 같을 수 있음
회의는 중단할 수 없으며, 회의가 끝남과 동시에 다음 회의가 진행할 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> conference;
int n;

void init()
{
    int start, end;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        conference.push_back(make_pair(start, end));
    }
    sort(conference.begin(), conference.end());
}

void solve()
{
    int cnt = 1;
    pair<int, int> pre = conference[0];
    for (int i = 1; i < n; i++)
    {
        if (conference[i].first < pre.second && conference[i].second < pre.second)
        {
            pre = conference[i];
        }
        else if (conference[i].first >= pre.second && conference[i].second >= pre.second)
        {
            cnt++;
            pre = conference[i];
        }
    }
    cout << cnt << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}