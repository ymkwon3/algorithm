#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "";
    int max = 0;
    for (int i = 0; i < table.size(); i++)
    {
        map<string, int> m;
        int cnt = 5;
        int sum = 0;
        string type = "";
        string temp = "";
        for (int j = 0; j < table[i].size(); j++)
        {
            char t = table[i][j];
            if (t != ' ')
            {
                temp += t;
            }
            else if (type == "")
            {
                type = temp;
                temp = "";
            }
            else
            {
                m[temp] = cnt;
                cnt--;
                temp = "";
            }
            if (j == table[i].size() - 1)
            {
                m[temp] = cnt;
            }
        }
        for (int j = 0; j < languages.size(); j++)
        {
            sum += m[languages[j]] * preference[j];
        }
        if (max == 0 || max <= sum)
        {
            if (max == sum)
            {
                answer = answer.compare(type) < 0 ? answer : type;
            }
            else
            {
                answer = type;
            }
            max = sum;
        }
    }
    return answer;
}

int main(void)
{
    vector<string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
    vector<string> languages = {"JAVA", "JAVASCRIPT"};
    vector<int> preference = {7, 5};

    solution(table, languages, preference);

    return 0;
}