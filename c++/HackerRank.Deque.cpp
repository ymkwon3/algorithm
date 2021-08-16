#include <iostream>
#include <deque>
#define endl '\n';
using namespace std;

int getMax(int start, int end, deque<int> &dq)
{
    int m = 0;
    for (int i = start; i < end; i++)
    {
        if (dq[i] > m)
            m = dq[i];
    }
    return m;
}

void printKMax(int arr[], int n, int k)
{
    //Write your code here.
    deque<int> dq;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        dq.push_back(arr[i]);
    }
    while (dq.size() >= k)
    {
        if (maxi == 0)
        {
            maxi = getMax(0, k, dq);
        }
        else
        {
            if (maxi < dq[k - 1])
                maxi = dq[k - 1];
        }
        cout << maxi << " ";
        if (maxi == dq.front())
            maxi = 0;
        dq.pop_front();
    }
    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}