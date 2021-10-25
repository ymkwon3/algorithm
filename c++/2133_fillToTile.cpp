#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(31);
    v[0] = 1;
    v[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        v[i] = v[i - 2] * v[2];
        for (int j = i - 4; j >= 0; j -= 2)
        {
            v[i] += v[j] * 2;
        }
    }
    cout << v[n] << "\n";
    return 0;
}