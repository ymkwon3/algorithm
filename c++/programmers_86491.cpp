#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int width = 0, height = 0;
    int cmpW, cmpH;
    for (auto i : sizes)
    {
        if (i[0] > i[1])
        {
            cmpW = i[0];
            cmpH = i[1];
        }
        else
        {
            cmpW = i[1];
            cmpH = i[0];
        }
        if (cmpW > width)
            width = cmpW;
        if (cmpH > height)
            height = cmpH;
    }
    answer = width * height;
    return answer;
}

int main(void)
{
    solution({{60, 50}, {30, 70}, {60, 30}, {80, 40}});
    return 0;
}