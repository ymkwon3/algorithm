#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    int n;
    int answer = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        map<char, int> m;
        cin >> word;
        char pre = word[0];
        for (int j = 0; j < word.size(); j++)
        {
            if (pre != word[j] && m[word[j]] > 0)
                break;
            m[word[j]]++;
            pre = word[j];
            if (j == word.size() - 1)
                answer++;
        }
    }
    cout << answer;
    return 0;
}