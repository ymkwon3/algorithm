#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> m;

    for (int i = 0; i < completion.size(); i++)
    {
        m[participant[i]]++;
        m[completion[i]]--;
    }
    m[participant[participant.size() - 1]]++;

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second == 1)
            answer = iter->first;
    }

    return answer;
}