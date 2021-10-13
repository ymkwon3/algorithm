#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int inputNum;
    cin >> inputNum;
    vector<int> vectorNum;
    for (int i = 0; i < inputNum; i++)
    {
        int dummyNum;
        cin >> dummyNum;
        vectorNum.push_back(dummyNum);
    }
    sort(vectorNum.begin(), vectorNum.end());
    cin >> inputNum;
    for (int i = 0; i < inputNum; i++)
    {
        int findNum;
        cin >> findNum;
        vector<int>::iterator it = lower_bound(vectorNum.begin(), vectorNum.end(), findNum);
        if (vectorNum[it - vectorNum.begin()] == findNum)
        {
            cout << "Yes " << it - vectorNum.begin() + 1 << endl;
        }
        else
        {
            cout << "No " << it - vectorNum.begin() + 1 << endl;
        }
    }
    return 0;
}