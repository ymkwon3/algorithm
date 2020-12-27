#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> input;
vector<int> fre_vector;
int n;

void init()
{
    cin >> n;
    for (int a, i = 0; i < n; i++)
    {
        cin >> a;
        input.push_back(a);
    }
}

void average()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += input[i];
    }
    cout << round(double(sum) / n) << "\n";
}

void center()
{
    cout << input[n / 2] << "\n";
}

void frequency()
{
    int pre, max, sum = 0, cnt = 0;
    if (n == 1)
    {
        cout << input[0] << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pre = input[i];
            cnt++;
            continue;
        }
        if (input[i] == pre)
        {
            cnt++;
            if (i == n - 1)
            {
                fre_vector.push_back(cnt);
            }
        }
        else
        {
            fre_vector.push_back(cnt);
            pre = input[i];
            cnt = 1;
        }
    }
    max = *max_element(fre_vector.begin(), fre_vector.end());
    cnt = count(fre_vector.begin(), fre_vector.end(), max);
    if (cnt == 1)
    {
        for (int i = 0; i < fre_vector.size(); i++)
        {
            sum += fre_vector[i];
            if (fre_vector[i] == max)
                break;
        }
    }
    else
    {
        int second = 0;
        for (int i = 0; i < fre_vector.size(); i++)
        {
            sum += fre_vector[i];
            if (fre_vector[i] == max)
            {
                second++;
                if (second == 2)
                    break;
            }
        }
    }

    cout << input[sum - 1] << "\n";
}

void range()
{
    int mini = 4001, maxi = -4001;
    for (int i = 0; i < n; i++)
    {
        if (input[i] < mini)
        {
            mini = input[i];
        }
        if (input[i] > maxi)
        {
            maxi = input[i];
        }
    }
    cout << maxi - mini << "\n";
}

void solve()
{
    sort(input.begin(), input.end());
    average();
    center();
    frequency();
    range();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}