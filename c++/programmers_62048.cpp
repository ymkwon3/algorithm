#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int r;
    if (b > a)
    {
        r = b;
        b = a;
        a = r;
    }

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w, int h)
{
    int g = gcd(w, h);
    return (w / g + h / g - 1) * g;
}

int main()
{
    solution(8, 12);
    return 0;
}