#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> m;
    m["c="] = 1, m["c-"] = 1;
    m["dz="] = 1, m["d-"] = 1;
    m["lj"] = 1;
    m["nj"] = 1;
    m["s="] = 1;
    m["z="] = 1;

    string s;
    cin >> s;

    int answer = 0;
    for (int i = 0; i < s.size();)
    {
        string word2 = "", word3 = "";
        if (i + 1 < s.size())
        {
            word2 += s[i], word2 += s[i + 1];
            if (m[word2] == 1)
            {
                answer++;
                i += 2;
                continue;
            }
        }
        if (i + 2 < s.size())
        {
            word3 += word2, word3 += s[i + 2];
            if (m[word3] == 1)
            {
                answer++;
                i += 3;
                continue;
            }
        }
        answer++;
        i++;
    }
    cout << answer << "\n";
    return 0;
}