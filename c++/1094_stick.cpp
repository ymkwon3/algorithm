#include <iostream>

using namespace std;

int main(void)
{
    int x, answer = 0;
    cin >> x;
    while (x > 0)
    {
        if (x % 2 == 1)
            answer++;
        x /= 2;
    }
    cout << answer << "\n";
    return 0;
}