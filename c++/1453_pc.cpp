#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, reject = 0;
    vector<int> v(101);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (v[input] != 0)
            reject++;
        else
            v[input]++;
    }
    cout << reject << "\n";
    return 0;
}