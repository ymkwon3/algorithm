#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    int n;
    string best;
    int max = 0;
    cin >> n;
    map<string, int> m;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        m[input]++;
        if (m[input] > max)
        {
            max = m[input];
            best = input;
        }
        else if (max == m[input] && input < best)
            best = input;
    }
    cout << best << "\n";
    return 0;
}