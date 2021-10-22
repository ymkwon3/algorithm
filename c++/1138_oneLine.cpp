#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> answer(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (answer[j] == 0)
                cnt++;
            if (cnt > v[i])
            {
                answer[j] = i + 1;
                break;
            }
        }
    }
    for (int a : answer)
    {
        cout << a << " ";
    }

    return 0;
}