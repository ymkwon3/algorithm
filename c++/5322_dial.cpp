#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    string s;
    cin >> s;

    int answer = 0;
    for (char c : s)
    {
        answer += v[c - 65];
    }
    cout << answer << "\n";
    return 0;
}