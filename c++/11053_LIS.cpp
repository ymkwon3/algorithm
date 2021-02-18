#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;

    cin >> n;
    cin >> tmp;
    a.push_back(tmp);
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < a.size(); j++)
        {
            if (tmp <= a[j])
            {
                a[j] = tmp;
                break;
            }
            else if (j == a.size() - 1)
                a.push_back(tmp);
        }
    }
    cout << a.size() << "\n";
    return 0;
}