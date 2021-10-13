#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    map<char, int> m;
    do
    {
        for (int i = 0; i < friends.size(); i++)
            m[friends[i]] = i;

        int cnt = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i][3] == '=' && abs(m[data[i][0]] - m[data[i][2]]) - 1 == data[i][4] - '0')
            {
                cnt++;
            }
            else if (data[i][3] == '<' && abs(m[data[i][0]] - m[data[i][2]]) - 1 < data[i][4] - '0')
            {
                cnt++;
            }
            else if (data[i][3] == '>' && abs(m[data[i][0]] - m[data[i][2]]) - 1 > data[i][4] - '0')
            {
                cnt++;
            }
            if (cnt == data.size())
                answer++;
        }
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}

int main()
{
    vector<string> s = {"N~F=0", "R~T>2"};
    solution(2, s);
}