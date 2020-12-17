#include <iostream>
using namespace std;

int brute[10001];
int n;

void init()
{
    brute[0] = 0;
    int cnt;
    int i = 1;
    int j = 666;
    int a;
    while (i < 10001)
    {
        cnt = 0;
        a = j;
        while (a != 0)
        {
            if (a % 10 == 6)
            {
                a /= 10;
                cnt++;
                if (cnt == 3)
                {
                    brute[i] = j;
                    i++;
                    break;
                }
                continue;
            }
            a /= 10;
            cnt = 0;
        }
        j++;
    }
    cin >> n;
    cout << brute[n] << "\n";
}

int main(void)
{
    init();
    return 0;
}