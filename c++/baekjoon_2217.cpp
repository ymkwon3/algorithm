#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        long long tmp = v[i] * (i + 1);
        answer = tmp > answer ? tmp : answer;
    }
    cout << answer << "\n";
    return 0;
}