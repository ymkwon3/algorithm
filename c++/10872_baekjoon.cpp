#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int fibo = 1;
    if (n == 0 || n == 1)
        cout << fibo << "\n";
    else
    {
        while (n > 0)
        {
            fibo *= n;
            n--;
        }
        cout << fibo << "\n";
    }
    return 0;
}