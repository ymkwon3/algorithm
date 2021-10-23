#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int t;
    long long x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        double dist = y - x;
        double dpow = sqrt(dist);
        int pow = round(dpow);
        cout << ((dpow <= pow) ? (pow * 2 - 1) : (pow * 2)) << "\n";
    }
    return 0;
}