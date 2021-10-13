#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> arr;
    int a, tmp, start, end;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> tmp;
    arr.erase(arr.begin() + tmp - 1);
    cin >> start >> end;
    arr.erase(arr.begin() + start - 1, arr.begin() + end - 1);
    cout << arr.size() << "\n";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
