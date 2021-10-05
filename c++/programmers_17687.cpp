#include <string>
#include <vector>
#include <iostream>
using namespace std;

string nNumber(int n, int number)
{
    string result = "";
    if (number == 0)
        return "0";
    while (number != 0)
    {
        string remainder = to_string(number % n);
        if (remainder == "10")
            result = "A" + result;
        else if (remainder == "11")
            result = "B" + result;
        else if (remainder == "12")
            result = "C" + result;
        else if (remainder == "13")
            result = "D" + result;
        else if (remainder == "14")
            result = "E" + result;
        else if (remainder == "15")
            result = "F" + result;
        else
            result = remainder + result;
        number /= n;
    }
    return result;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    string tmp = "";
    for (int i = 0; i <= t * m; i++)
    {
        tmp += nNumber(n, i);
    }
    for (int i = p; i <= t * m; i += m)
    {
        answer += tmp[i - 1];
    }
    return answer;
}

int main(void)
{
    solution(16, 16, 2, 1);
    return 0;
}