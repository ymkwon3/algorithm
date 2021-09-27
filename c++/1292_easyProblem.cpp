#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    int j = 1;
    while (v.size() < 1000)
    {
        for (int i = 0; i < j; i++)
        {
            v.push_back(j);
        }
        j++;
    }

    int answer = 0;
    int left, right;
    cin >> left >> right;
    for (int i = left; i <= right; i++)
        answer += v[i - 1];

    cout << answer << "\n";
    return 0;
}