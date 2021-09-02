#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    bool is = false;

    while (k > 0)
    {
        if (number.size() == k)
        {
            is = true;
            break;
        }
        string front = number.substr(0, k + 1);
        string back = number.substr(k + 1, number.size());
        int maxIdx = 0;
        for (int i = 0; i < front.size(); i++)
        {
            if (front[maxIdx] < front[i])
                maxIdx = i;
        }
        answer += front[maxIdx];
        front = front.substr(maxIdx + 1, front.size());
        number = front + back;
        k -= maxIdx;
    }
    answer = is ? answer : answer + number;
    cout << answer << "\n";
    return answer;
}

int main()
{
    solution("1119", 2);
    solution("99123", 2);
    solution("1231234", 3);
    solution("4177252841", 4);
    return 0;
}