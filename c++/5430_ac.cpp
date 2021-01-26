/*
테스트케이스 t
함수 p, r(reverse), d(delete)
수의 개수 n
배열 arr
다 풀고 deque 문제라는것을 알았다...힝
*/

#include <iostream>
#include <vector>

using namespace std;

void solve();

void init()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}

void solve()
{
    bool isR = false, isError = false;
    vector<int> v;
    string p, arr, tmp;
    int n, start, end;
    cin >> p;
    cin >> n;
    cin >> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] == ',' && tmp.size() > 0) || i == arr.size() - 1)
        {
            if (tmp.size() == 0)
            {
                break;
            }
            else
            {
                v.push_back(stoi(tmp));
                tmp.clear();
            }
        }
        else if (arr[i] != '[' && arr[i] != ']' && arr[i] != ',')
        {
            tmp.push_back(arr[i]);
        }
    }
    start = 0;
    end = v.size() - 1;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == 'R')
        {
            if (!isR)
                isR = true;
            else
                isR = false;
        }
        else
        {
            if (start > end)
                isError = true;
            if (!isR)
                start++;
            else
                end--;
        }
    }
    if (isError)
        cout << "error\n";
    else
    {
        cout << "[";
        if (!isR)
        {
            for (int i = start; i <= end; i++)
            {
                cout << v[i];
                if (i != end)
                    cout << ",";
            }
        }
        else
        {
            for (int i = end; i >= start; i--)
            {
                cout << v[i];
                if (i != start)
                    cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    return 0;
}