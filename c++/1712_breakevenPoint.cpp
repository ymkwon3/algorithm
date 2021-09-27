#include <iostream>

int main(void)
{
    int a, b, c;
    int answer = 1;
    std::cin >> a >> b >> c;
    if (b >= c)
    {
        std::cout << -1 << "\n";
        return 0;
    }
    answer += a / (c - b);
    std::cout << answer << "\n";
    return 0;
}
