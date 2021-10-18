#include <string>
#include <vector>

using namespace std;

int solution(int n)
{

    for (int answer = 1; answer <= n; answer++)
    {
        if (n % answer == 1)
            return answer;
    }
}