#include <iostream>
#include <vector>

using namespace std;

vector<int> pascal[11];
int n, k;

void init()
{
    for (int i = 0; i < 11; i++)
    {
        pascal[i].push_back(1);

        for (int j = 1; j < i + 1; j++)
        {
            if (j == i)
                pascal[i].push_back(1);
            else
                pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
        }
    }

    cin >> n >> k;
    cout << pascal[n][k] << "\n";
}

int main(void)
{
    init();
    return 0;
}