#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    long min = 0, max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            min += arr[i];
        }
        else if (i == arr.size() - 1)
        {
            max += arr[i];
        }
        else
        {
            min += arr[i];
            max += arr[i];
        }
    }
    cout << min << " " << max << "\n";
}