#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, input, sum = 0;
    cin >> n;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        sum += input;
        answer.push_back(sum);
        if (sum < 0)
            sum = 0;
    }

    sort(answer.begin(), answer.end(), greater<int>());

    cout << answer[0] << "\n";

    return 0;
}