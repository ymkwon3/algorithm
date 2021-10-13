#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(vector<int> candles)
{
    int maxi = 0, cnt = 0;
    for (int i : candles)
    {
        if (i > maxi)
        {
            maxi = i;
            cnt = 1;
        }
        else if (i == maxi)
            cnt++;
    }
    cout << cnt << "\n";
    return cnt;
}