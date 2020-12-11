#include <iostream>

using namespace std;
char a[4], b[4];
char tmp;

void init()
{
    cin >> a >> b;
}

void reverse(char *c)
{
    tmp = c[0];
    c[0] = c[2];
    c[2] = tmp;
}

void compare()
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            cout << a[0] << a[1] << a[2] << "\n";
            return;
        }
        else if (b[i] > a[i])
        {
            cout << b[0] << b[1] << b[2] << "\n";
            return;
        }
    }
}

int main(void)
{
    init();
    reverse(a);
    reverse(b);
    compare();
    return 0;
}