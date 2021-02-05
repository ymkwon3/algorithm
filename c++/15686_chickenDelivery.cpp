/*
알고리즘 분류를 보기 전 아무리 생각해도 브루트포스 외에는 생각이 안났다.
도저히 풀 방법이 생각이 안나 분류를 보니 브루트포스....
어떻게 브루트포스를 할까 생각을 하다가 치킨집의 조합으로 계산하는게 생각이나
조합하는 방법을 찾아보며 구현하였다.
어떻게 조합을 구현하는지 알았으니 다음에는 안보고 구현할 수 있도록 하자.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> d;
int n, m;

void distance(int chicken_index)
{
    int sub;
    for (int i = 0; i < home.size(); i++)
    {
        sub = abs(home[i].first - chicken[chicken_index].first) + abs(home[i].second - chicken[chicken_index].second);
        if (d[i] > sub)
            d[i] = sub;
    }
}

void combination()
{
    int min = -1, sum;
    vector<bool> comb_chicken(chicken.size());
    for (int i = 0; i < m; i++)
        comb_chicken[i] = true;
    do
    {
        d.assign(home.size(), 200);
        sum = 0;
        for (int i = 0; i < chicken.size(); i++)
        {
            if (comb_chicken[i])
                distance(i);
        }
        for (int i = 0; i < d.size(); i++)
            sum += d[i];
        if (min == -1 || min > sum)
            min = sum;
    } while (prev_permutation(comb_chicken.begin(), comb_chicken.end()));

    cout << min << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (a == 1)
                home.push_back(make_pair(i, j));
            else if (a == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    combination();

    return 0;
}