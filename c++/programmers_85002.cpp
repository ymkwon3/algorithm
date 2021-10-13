#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Boxer
{
public:
    int num;
    int weight;
    double rate;
    int winHeavier;
    Boxer(int _num, int _weight, double _rate, int _winHeavier) : num(_num), weight(_weight), rate(_rate), winHeavier(_winHeavier){};
};

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<int> answer;
    vector<Boxer> boxers;
    int boxerNum = weights.size();
    for (int i = 0; i < boxerNum; i++)
    {
        double rate = 0;
        int numerator = 0;
        int denominator = 0;
        int winHeavier = 0;
        for (int j = 0; j < boxerNum; j++)
        {
            if (head2head[i][j] != 'N')
            {
                denominator++;
            }
            if (head2head[i][j] == 'W')
            {
                numerator++;
                if (weights[i] < weights[j])
                {
                    winHeavier++;
                }
            }
        }
        rate = denominator == 0 ? 0 : (double)numerator / (double)denominator;
        boxers.push_back(Boxer(i + 1, weights[i], rate, winHeavier));
    }

    sort(boxers.begin(), boxers.end(), [](Boxer a, Boxer b)
         {
             if (a.rate == b.rate) // 승률이 같을 경우
             {
                 if (a.winHeavier == b.winHeavier) // 자신보다 몸무게가 무거운 복서를 이긴 횟수가 같을 경우
                 {
                     if (a.weight == b.weight) // 몸무게가 같을 경우
                     {
                         return a.num < b.num ? true : false;
                     }
                     else
                         return a.weight > b.weight ? true : false;
                 }
                 else
                     return a.winHeavier > b.winHeavier ? true : false;
             }
             else
                 return a.rate > b.rate ? true : false;
         });

    for (auto i : boxers)
    {
        answer.push_back(i.num);
    }
    return answer;
}

int main()
{
    solution({60, 70, 60}, {"NNN", "NNN", "NNN"});
    return 0;
}