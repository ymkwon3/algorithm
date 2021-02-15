#include <iostream>

using namespace std;

int sticker[2][111111];
int testcase, n;

int solve(int start)
{
    int tmp, currentT = 2, reverseT = 2, prev = 0, next = 0, sum = 0;
    currentT = start;
    start == 0 ? reverseT = 1 : reverseT = 0;
    sum += sticker[start][0];
    prev = sticker[start][0];
    if (n - 2 > 0)
        next = sticker[start][2];
    else
        next = 0;
    for (int i = 1; i < n; i++)
    {
        if (prev + sticker[reverseT][i] + next <= sticker[currentT][i])
        {
            sum -= prev;
            sum += sticker[currentT][i];
            prev = sticker[currentT][i];
            if (i < n - 2)
                next = sticker[currentT][i + 2];
            else
                next = 0;
            continue;
        }
        sum += sticker[reverseT][i];
        prev = sticker[reverseT][i];
        if (i < n - 2)
            next = sticker[reverseT][i + 2];
        else
            next = 0;
        tmp = currentT;
        currentT = reverseT;
        reverseT = tmp;
    }
    return sum;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
                cin >> sticker[j][k];
        }
        int result = max(solve(0), solve(1));
        cout << result << "\n";
    }

    return 0;
}