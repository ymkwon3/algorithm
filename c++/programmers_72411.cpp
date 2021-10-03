#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, int> si;

void combination(string order, vector<char> comb, int index, int depth, map<string, int> &m)
{
    if (depth == comb.size())
    {
        string s = "";
        for (int i = 0; i < comb.size(); i++)
        {
            s += comb[i];
        }
        sort(s.begin(), s.end());
        m[s]++;
        return;
    }
    else
    {
        for (int i = index; i < order.size(); i++)
        {
            comb[depth] = order[i];
            combination(order, comb, i + 1, depth + 1, m);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    vector<int> an(course[course.size() - 1] + 1);
    map<string, int> m;
    map<string, int>::iterator iter;
    for (auto a : orders)
    {
        for (int i = 0; i < course.size(); i++)
        {
            vector<char> c(course[i]);
            combination(a, c, 0, 0, m);
        }
    }
    vector<si> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](si a, si b)
         { return a.second > b.second; });
    for (si i : v)
    {
        cout << i.first << " " << i.second << "\n";
        if ((an[i.first.size()] == 0 || an[i.first.size()] == i.second) && i.second > 1)
        {
            an[i.first.size()] = i.second;

            answer.push_back(i.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(void)
{
    solution({"XYZ", "XWY", "WXA"}, {2, 3, 4});
    return 0;
}