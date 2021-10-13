#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (abs(a - b) != 1 || a / 2 == b / 2)
    {
        a = a % 2 == 0 ? a / 2 : a / 2 + 1;
        b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        answer++;
    }
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution(8, 4, 5);
    return 0;
}