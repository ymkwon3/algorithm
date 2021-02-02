#include <iostream>
#include <math.h>

using namespace std;
int N, a, b, cnt = -1;

void divide(int q, int w, int e, int r)
{
    if (e == a && q == b)
    {
        cnt++;
        cout << cnt << "\n";
        return;
    }
    int div = pow(2, N) * pow(2, N);
    if (div == 2)
        div = 1;
    div /= 4;
    N--;
    if (w - q != 0 && r - e != 0)
    {
        if ((b >= q && b < (q + w) / 2) && (a >= e && a < (e + r) / 2))
        {
            divide(q, (q + w) / 2, e, (e + r) / 2);
            return;
        }
        cnt += div;
        if ((b >= (q + w) / 2 && b < w) && (a >= e && a < (e + r) / 2))
        {

            divide((q + w) / 2, w, e, (e + r) / 2);
            return;
        }
        cnt += div;
        if ((b >= q && b < (q + w) / 2) && (a >= (e + r) / 2 && a < r))
        {
            divide(q, (q + w) / 2, (e + r) / 2, r);
            return;
        }
        cnt += div;
        if ((b >= (q + w) / 2 && b < w) && (a >= (e + r) / 2 && a < r))
        {
            divide((q + w) / 2, w, (e + r) / 2, r);
            return;
        }
        cnt += div;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> a >> b;
    divide(0, pow(2, N), 0, pow(2, N));
    return 0;
}