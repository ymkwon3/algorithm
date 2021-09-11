#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    int init = 0;
    int maxi = 0;
    int arrow;
    if (info[0] == n)
    {
        answer = {-1};
        return answer;
    }
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i] > 0)
            init += 10 - i;
    }
    for (int i = 0; i < info.size(); i++)
    {
        vector<int> tmp(info.size(), 0);
        int l = 0, a = init;
        arrow = n;
        for (int j = i; j < info.size(); j++)
        {
            if (arrow > info[j])
            {
                tmp[j] = info[j] + 1;
                arrow -= info[j] + 1;
                l += 10 - j;
                if (info[j] > 0)
                    a -= 10 - j;
            }
            if (arrow == 0)
                break;
        }
        if (arrow > 0)
            tmp[info.size() - 1] = arrow;
        if (l - a > maxi)
        {
            answer = tmp;
            maxi = l - a;
        }
    }

    arrow = n;
    int l = 0, a = init;
    vector<int> tmp(info.size(), 0);
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j < info.size(); j++)
        {
            if (arrow <= 0)
                break;
            if (info[j] == i && arrow > i)
            {
                arrow -= i + 1;
                tmp[j] = i + 1;
                l += 10 - j;
                if (i > 0)
                    a -= 10 - j;
            }
        }
    }
    tmp[info.size() - 1] = arrow;
    if (l - a >= maxi)
        answer = tmp;
    cout << l - a << " " << maxi << "\n";
    for (int i : answer)
    {
        cout << i << " ";
    }

    return answer;
}

int main()
{
    solution(10, {9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    return 0;
}