#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long num)
{
    if (num < 2)
        return false;
    for (long long i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    int answer = 0;
    string conv = "";
    while (n != 0)
    {
        conv = to_string(n % k) + conv;
        n /= k;
    }
    cout << conv << "\n";
    string s = "";
    for (int i = 0; i < conv.size(); i++)
    {
        if (conv[i] != '0')
        {
            s += conv[i];
        }
        else
        {
            if (s != "" && isPrime(stoll(s)))
                answer++;
            s = "";
        }
    }
    if (s != "" && isPrime(stoll(s)))
        answer++;
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution(118097, 3);
    return 0;
}