#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutation(vector<int> v, int depth, int n, int r, int &answer, map<int, int> &m)
{
    if (depth == r)
    {
        int value = 0;
        for (int i = 0; i < r; i++)
        {
            value = value * 10 + v[i];
        }
        if (m[value] == 0)
        {
            m[value] = 1;
            cout << value << "\n";
            for (int i = 2; i <= value; i++)
            {
                if (i != value && value % i == 0)
                    break;
                else if (i == value)
                {
                    answer++;
                }
            }
        }
    }

    for (int i = depth; i < n; i++)
    {
        swap(v[depth], v[i]);
        permutation(v, depth + 1, n, r, answer, m);
        swap(v[depth], v[i]);
    }
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> v;
    map<int, int> m;
    for (char c : numbers)
        v.push_back(c - '0');
    for (int i = 1; i <= v.size(); i++)
    {
        permutation(v, 0, v.size(), i, answer, m);
    }
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution("011");
    return 0;
}