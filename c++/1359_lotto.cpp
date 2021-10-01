#include <iostream>
#include <cstdio>
using namespace std;

int comb(int n, int r)
{
    int a = 1, b = 1;
    for (int i = n; i > n - r; i--)
        a *= i;
    for (int i = r; i > 0; i--)
        b *= i;

    return a / b;
}

int main(void)
{
    int n, m, k;

    cin >> n >> m >> k;
    double result = 0.0;
    double a = comb(n, m);
    while (m >= k)
    {
        if (n - m < m - k)
        {
            k++;
            continue;
        }
        double d = comb(m, k) * comb(n - m, m - k);
        result += d / a;
        k++;
    }
    printf("%.16f", result);
    return 0;
}

/* 
첫 시도 방법...
문제를 이해하기론 n까지의 수 중에서 고른 m개의 수에서 최소 k개의 수가 같으면 당첨이라는 말이
예를들어 n이 3, m이 2, k이 1일 경우
1 2 3 에서
1 2
1 3
2 3 가 나오게 된다.
그러면 이 때, 1 2일 경우 최소 하나가 맞을 확률은 2 / 3 가 되게 된다.
따라서 하나를 뽑을 확률과 위의 확률을 곱한
1 / 3 * 2 / 3 가 답이 되게 풀이 했다...
문제이해를 잘못했나?

두번째 시도...
문제를 다르게 이해해보았다.
1 2 3 의 보기와
1 2
1 3
2 3
의 경우에서 k가 1일 경우 당첨될 수 있는 확률은 2 / 3가 나오도록 이해했다.

세번째 시도...
“1부터 N까지의 수 중에 서로 다른 M개의 수를 골라보세요. 저희도 1부터 N까지의 수 중에 서로 다른 M개의 수를 고를건데, 적어도 K개의 수가 같으면 당첨입니다.!”
의 지문을 자세히 읽으니 문제가 완전 달라졌다...
*/