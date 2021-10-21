#include <iostream>
using namespace std;
int main(void)
{
    int e, s, m;
    int E = 1, S = 1, M = 1;
    int y = 1;
    cin >> e >> s >> m;
    while (e != E || s != S || m != M)
    {
        E++, S++, M++;
        if (E > 15)
            E = 1;
        if (S > 28)
            S = 1;
        if (M > 19)
            M = 1;
        y++;
    }
    cout << y << "\n";
    return 0;
}