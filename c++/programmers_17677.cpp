#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    map<string, int> v1_map; //교집합
    vector<string> g;        //교집합
    vector<string> h;        //합집합
    for (int i = 0; i < str1.size() - 1; i++)
    {
        string tmp = "";
        if (((str1[i] >= 65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122)) &&
            ((str1[i + 1] >= 65 && str1[i + 1] <= 90) || (str1[i + 1] >= 97 && str1[i + 1] <= 122)))
        {
            if (str1[i] >= 65 && str1[i] <= 90)
                str1[i] = str1[i] + 32;
            if (str1[i + 1] >= 65 && str1[i + 1] <= 90)
                str1[i + 1] = str1[i + 1] + 32;
            tmp += str1[i];
            tmp += str1[i + 1];
            v1.push_back(tmp);
            v1_map[tmp]++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string tmp = "";
        if (((str2[i] >= 65 && str2[i] <= 90) || (str2[i] >= 97 && str2[i] <= 122)) &&
            ((str2[i + 1] >= 65 && str2[i + 1] <= 90) || (str2[i + 1] >= 97 && str2[i + 1] <= 122)))
        {
            if (str2[i] >= 65 && str2[i] <= 90)
                str2[i] = str2[i] + 32;
            if (str2[i + 1] >= 65 && str2[i + 1] <= 90)
                str2[i + 1] = str2[i + 1] + 32;
            tmp += str2[i];
            tmp += str2[i + 1];
            v2.push_back(tmp);
            if (v1_map[tmp] != 0)
            {
                g.push_back(tmp);
                v1_map[tmp]--;
            }
        }
    }
    h = v1;
    for (int i = 0; i < v2.size(); i++)
        h.push_back(v2[i]);
    double j;
    if (double(h.size() - g.size()) == 0)
        j = 1;
    else
        j = double(g.size()) / (double(h.size() - g.size()));
    j *= 65536;
    answer = j;
    return answer;
}

int main(void)
{
    solution("E=M*C^2", "e=m*c^2");
    return 0;
}