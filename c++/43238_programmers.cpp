#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll solution(int n, vector<int> times)
{
    ll answer = 0;
    ll minT = 1, maxT, avgT, h = 0;
    maxT = *max_element(times.begin(), times.end()) * (ll)n;
    while (minT <= maxT)
    {
        avgT = (minT + maxT) / 2;
        for (auto t : times)
            h += avgT / t;
        if (n <= h)
        {
            answer = avgT;
            maxT = avgT - 1;
        }
        else
            minT = avgT + 1;
        h = 0;
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    solution(10, {1, 2, 3, 10});
    return 0;
}