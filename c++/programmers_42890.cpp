#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<string> subKey;

int combination(vector<int> v, vector<int> comb, int index, int depth, vector<vector<string>> relation)
{
    int result = 0;
    if (depth == comb.size())
    {

        for (auto i : subKey)
        {
            int cnt = 0;
            for (auto j : comb)
            {
                string cmp = to_string(j) + "/";
                if (i.find(cmp) != string::npos)
                    cnt++;
                if (cnt == i.size() - cnt)
                    return 0;
            }
        }
        set<string> s;
        vector<int> used;
        for (int j = 0; j < relation.size(); j++)
        {
            string key = "";

            for (int k = 0; k < comb.size(); k++)
            {
                key += relation[j][comb[k]] + "/";
                if (j == 0)
                {
                    used.push_back(comb[k]);
                }
            }
            s.insert(key);
        }

        if (s.size() == relation.size())
        {
            string test = "";
            for (auto i : used)
                test += to_string(i) + "/";
            subKey.push_back(test);
            return 1;
        }

        return 0;
    }
    else
    {
        for (int i = index; i < v.size(); i++)
        {
            comb[depth] = v[i];
            result += combination(v, comb, i + 1, depth + 1, relation);
        }
    }
    return result;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    vector<int> cnt;
    for (int i = 0; i < relation[0].size(); i++)
        cnt.push_back(i);
    for (int i = 1; i <= relation[0].size(); i++)
    {
        vector<int> r(i);
        answer += combination(cnt, r, 0, 0, relation);
    }
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution({{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}});
    return 0;
}