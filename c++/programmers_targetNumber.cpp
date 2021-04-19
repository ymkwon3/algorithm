#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(int value, int index, int target, vector<int> numbers)
{
    int cnt = 0;
    if (index == numbers.size())
    {
        if (value == target)
            return 1;
        else
            return 0;
    }

    cnt += dfs(value + numbers[index], index + 1, target, numbers);
    cnt += dfs(value - numbers[index], index + 1, target, numbers);

    return cnt;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    answer += dfs(numbers[0], 1, target, numbers);
    answer += dfs(-numbers[0], 1, target, numbers);

    return answer;
}

int main(void)
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);

    cout << solution(numbers, 3) << endl;

    return 0;
}