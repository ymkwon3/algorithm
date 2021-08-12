#include <iostream>

using namespace std;

long long solution(int w, int h)
{
    long long answer = 1;
    long long minus = 0;
    if (w > h)
    {
        int tmp = h;
        h = w;
        w = tmp;
    }
    else if (w == h)
    {
        cout << (w * h) - w;

        return ((long long)w * (long long)h) - w;
    }

    if (h % w != 0)
    {
        minus += (long long)w;
    }
    minus += ((long long)h / (long long)w) * (long long)w;
    answer = ((long long)w * (long long)h) - minus;
    cout << answer;
    return answer;
}

int main(void)
{
    solution(9, 13);
    return 0;
}