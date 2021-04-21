#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    bool answer = true;
    map<string, int> m;
    for (int i = 0; i < phone_book.size(); i++)
    {
        string s = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            s += phone_book[i][j];
            if (m.find(s) != m.end())
            {
                answer = false;
            }
        }
        m[phone_book[i]]++;
    }

    cout << "size : " << phone_book.size() << "\n";

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " : " << iter->second << "\n";
    }
    cout << "ans = " << answer;

    return answer;
}

int main(void)
{
    vector<string> v;
    v.push_back("10");
    v.push_back("010");
    v.push_back("11");
    v.push_back("01");
    v.push_back("09");
    solution(v);

    return 0;
}