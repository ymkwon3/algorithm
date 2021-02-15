/*
파스칼의 삼각형은 조합이랑 같다.....알아두자...메..모..
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string pascal[101][101];
int n, m;

string sum(string a, string b)
{
    string bigger, smaller, result = "";
    int carry = 0;
    if (a.size() >= b.size())
    {
        bigger = a;
        smaller = b;
    }
    else
    {
        bigger = b;
        smaller = a;
    }
    reverse(bigger.begin(), bigger.end());
    reverse(smaller.begin(), smaller.end());
    for (int i = 0; i < smaller.size(); i++)
    {
        int s1 = smaller[i] - '0';
        int b1 = bigger[i] - '0';
        result.push_back(static_cast<char>((s1 + b1 + carry) % 10 + '0'));
        carry = (s1 + b1 + carry) / 10;
    }
    for (int i = smaller.size(); i < bigger.size(); i++)
    {
        int b1 = bigger[i] - '0';
        result.push_back(static_cast<char>((b1 + carry) % 10 + '0'));
        carry = (b1 + carry) / 10;
    }

    if (carry != 0)
        result.push_back(static_cast<char>(carry + '0'));

    reverse(result.begin(), result.end());

    return result;
}

void pascal_triangle()
{
    pascal[0][0] = "1";
    pascal[1][0] = "1";
    pascal[1][1] = "1";
    for (int i = 2; i < 101; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i)
                pascal[i][j] = "1";
            else
                pascal[i][j] = sum(pascal[i - 1][j - 1], pascal[i - 1][j]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    pascal_triangle();
    cout << pascal[n][m] << "\n";
    return 0;
}