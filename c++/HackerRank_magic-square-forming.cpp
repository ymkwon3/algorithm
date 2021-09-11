#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vectorLeftShift(vector<int> &v)
{
    int pre = v[v.size() - 1];
    int tmp;
    for (int i = v.size() - 2; i >= 0; i--)
    {
        tmp = v[i];
        v[i] = pre;
        pre = tmp;
        if (i == 0)
        {
            v[v.size() - 1] = pre;
        }
    }
}

void vectorRightShift(vector<int> &v)
{
    int pre = v[0];
    int tmp;
    for (int i = 1; i < v.size(); i++)
    {
        tmp = v[i];
        v[i] = pre;
        pre = tmp;
        if (i == v.size() - 1)
        {
            v[0] = pre;
        }
    }
}

int formingMagicSquare(vector<vector<int>> s)
{
    int sumR = 0, sumL = 0, min = 9999, initSum = 0;
    vector<int> answerR = {2, 7, 6, 1, 8, 3, 4, 9};
    vector<int> answerL = {2, 9, 4, 3, 8, 1, 6, 7};
    vector<int> cur = {s[0][0], s[0][1], s[0][2], s[1][2],
                       s[2][2], s[2][1], s[2][0], s[1][0]};
    if (s[1][1] != 5)
    {
        sumR += abs(s[1][1] - 5);
        sumL += abs(s[1][1] - 5);
        initSum = abs(s[1][1] - 5);
        s[1][1] = 5;
    }
    for (int i = 0; i < 4; i++)
    {
        int cnt = 0;
        while (true)
        {
            if (cnt == 4)
                break;
            if (answerL[0] != cur[0] && (cur[0] == 2 || cur[0] == 4 || cur[0] == 6 || cur[0] == 8))
            {
                cout << answerL[0] << " " << cur[0] << "\n";
                vectorLeftShift(answerR);
                vectorRightShift(answerL);
                cnt++;
            }
            else
                break;
        }

        for (int i = 0; i < 9; i++)
        {
            sumR += abs(answerR[i] - cur[i]);
            sumL += abs(answerL[i] - cur[i]);
        }
        cout << sumR << " " << sumL << "init" << initSum << "\n";
        if (min > sumR || min > sumL)
        {
            min = sumR > sumL ? sumL : sumR;
        }
        sumR = initSum, sumL = initSum;
        vectorLeftShift(cur);
        vectorLeftShift(cur);
    }
    cout << min << "\n";
    return min;
}

int main(void)
{
    formingMagicSquare({{3, 9, 4}, {3, 5, 6}, {7, 9, 3}});
    return 0;
}