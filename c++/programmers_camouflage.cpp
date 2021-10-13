#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m;
    for (vector<string> v : clothes)
    {
        m[v[1]]++;
    }
    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        answer *= iter->second + 1;
    }
    return answer - 1;
}

int main(void)
{
    vector<vector<string>> v = {{"1", "asd"}, {"1", "qwe"}, {"2", "asd"}};
    solution(v);
    return 0;
}