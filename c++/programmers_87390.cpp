#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    while (left <= right)
    {
        answer.push_back(max((left / n) + 1, (left % n) + 1));
        left++;
    }
    return answer;
}

int main(void)
{
    solution(3, 2, 5);
    return 0;
}