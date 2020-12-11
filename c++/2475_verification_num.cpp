#include <iostream>

using namespace std;

int a, b, c, d, e;
int verification;

void init()
{
    cin >> a >> b >> c >> d >> e;
    verification = (a * a + b * b + c * c + d * d + e * e) % 10;

    cout << verification << "\n";
}

int main(void)
{
    init();

    return 0;
}