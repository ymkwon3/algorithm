#include <iostream>
#include <vector>

using namespace std;
const int MAX = 15;
vector<vector<int>> apart;
int testCase, n, k;
int sum = 0;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        vector<int> element(MAX);
        apart.push_back(element);
    }
    for (int i = 1; i < MAX; i++)
    {
        apart[0][i] = i;
    }
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            sum += apart[i - 1][j];
            apart[i][j] = sum;
        }
        sum = 0;
    }
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> k;
        cin >> n;
        cout << apart[k][n] << "\n";
    }
}

int main(void)
{
    init();
    return 0;
}