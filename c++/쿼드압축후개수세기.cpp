#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zero = 0;

int quad(const vector<vector<int>> &arr, int row1, int row2, int col1, int col2)
{
    bool flag = false;
    int ans = arr[row1][col1];
    if (row2 - row1 != 1)
        cout << row1 << row2 << col1 << col2 << " " << ans << "\n";
    for (int i = row1; i < row2; i++)
    {
        for (int j = col1; j < col2; j++)
        {
            if (arr[i][j] != arr[row1][col1])
            {
                ans = 0;
                ans += quad(arr, row1, (row1 + row2) / 2, col1, (col1 + col2) / 2);

                ans += quad(arr, (row1 + row2) / 2, row2, col1, (col1 + col2) / 2);

                ans += quad(arr, row1, (row1 + row2) / 2, (col1 + col2) / 2, col2);

                ans += quad(arr, (row1 + row2) / 2, row2, (col1 + col2) / 2, col2);
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (ans == 0)
        zero++;
    return ans;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    int re = quad(arr, 0, arr.size(), 0, arr.size());
    answer.push_back(zero);
    answer.push_back(re);
    return answer;
}

int main(void)
{
    vector<vector<int>> arr = {{1, 1, 0, 0},
                               {1, 0, 0, 0},
                               {1, 0, 0, 1},
                               {1, 1, 1, 1}};
    solution(arr);
    return 0;
}