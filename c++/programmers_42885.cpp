#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    int tmp = 0;
    for (int i = people.size() - 1, j = 0; i >= j; i--)
    {
        tmp += people[i];
        if (tmp == limit)
        {
            tmp = 0;
            answer++;
        }
        else if (tmp < limit)
        {
            while (true)
            {
                tmp += people[j];
                if (tmp == limit)
                {
                    tmp = 0;
                    answer++;
                    j++;
                    break;
                }
                else if (tmp > limit)
                {
                    tmp = 0;
                    answer++;
                    break;
                }
                j++;
            }
        }
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    vector<int> p = {50, 100, 100, 150, 200};
    solution(p, 200);
    return 0;
}