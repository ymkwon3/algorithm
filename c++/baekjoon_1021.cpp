#include <deque>
#include <iostream>
using namespace std;

int main(void)
{
    int answer = 0;
    int n, m;
    int left, right;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    int input;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        for (int j = 0; j < dq.size(); j++)
        {
            if (dq[j] == input)
            {
                left = j;
                right = dq.size() - j;
                break;
            }
        }
        if (left <= right)
        {
            while (true)
            {
                if (dq.front() == input)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
        }
        else
        {
            answer++;
            while (true)
            {
                if (dq.back() == input)
                {
                    dq.pop_back();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}