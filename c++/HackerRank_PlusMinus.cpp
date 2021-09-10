#include <bits/stdc++.h>

using namespace std;

void plusMinus(vector<int> arr)
{
    cout << fixed;
    cout.precision(6);
    double minus = 0;
    double plus = 0;
    double zero = 0;
    double size = (double)arr.size();
    for (auto i : arr)
    {
        if (i < 0)
            minus++;
        else if (i > 0)
            plus++;
        else
            zero++;
    }

    cout << plus / size << "\n";
    cout << minus / size << "\n";
    cout << zero / size << "\n";
}