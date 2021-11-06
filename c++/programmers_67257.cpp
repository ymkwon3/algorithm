#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long calc(long long a, long long b, char c)
{
    if (c == '*')
        return a * b;
    else if (c == '-')
        return a - b;
    else if (c == '+')
        return a + b;
}

long long solution(string expression)
{
    vector<long long> value;
    vector<char> opt;
    long long result = 0;

    string tmp = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else
        {
            opt.push_back(expression[i]);
            value.push_back(stoll(tmp));
            tmp = "";
        }
    }
    value.push_back(stoll(tmp));

    vector<int> perm = {0, 1, 2};
    string op = "+-*";

    do
    {
        vector<long long> temp_value = value;
        vector<char> temp_op = opt;

        for (int i = 0; i < perm.size(); i++)
        {
            for (int j = 0; j < temp_op.size();)
            {
                if (temp_op[j] == op[perm[i]])
                {
                    long long res = calc(temp_value[j], temp_value[j + 1], temp_op[j]);
                    temp_value.erase(temp_value.begin() + j);
                    temp_value.erase(temp_value.begin() + j);
                    temp_value.insert(temp_value.begin() + j, res);
                    temp_op.erase(temp_op.begin() + j);
                }
                else
                    j++;
            }
        }
        result = max(result, abs(temp_value[0]));
    } while (next_permutation(perm.begin(), perm.end()));
    return result;
}