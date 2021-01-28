#include <iostream>
#include <queue>
#include <map>

using namespace std;

// priority_queue<int, vector<int>, greater<int>> pq; // 더 좋은 방법이 있구려...허허
// map<int, int> cmp;
// int n;

// void init()
// {
//     int a;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a;
//         if (a == 0)
//         {
//             if (pq.empty())
//             {
//                 cout << 0 << "\n";
//             }
//             else
//             {
//                 if (cmp[pq.top()] > 0)
//                 {
//                     cout << "-";
//                     cmp[pq.top()]--;
//                 }
//                 cout << pq.top() << "\n";
//                 pq.pop();
//             }
//         }
//         else
//         {
//             if (a < 0)
//             {
//                 cmp[abs(a)]++;
//             }
//             pq.push(abs(a));
//         }
//     }
// }

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(make_pair(abs(a), a));
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    return 0;
}