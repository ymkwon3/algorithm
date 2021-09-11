#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>

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

int main(void)
{
    vector<int> v = {1, 2, 3, 4, 5};
    vectorLeftShift(v);
    vectorRightShift(v);
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}