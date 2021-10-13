#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;

int calc(string a, string b)
{
    int aH = stoi(a.substr(0, 2)), aM = stoi(a.substr(3, 2));
    int bH = stoi(b.substr(0, 2)), bM = stoi(b.substr(3, 2));
    if (bM > aM)
    {
        aH--;
        aM += 60;
    }
    return (aH - bH) * 60 + (aM - bM);
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, string> m;
    set<string> cars;
    set<string>::iterator iter;
    for (string s : records)
    {
        int i = s.find(" ");
        m[s.substr(i + 1, 4)] += s.substr(0, 5) + " ";
        cars.insert(s.substr(i + 1, 4));
    }
    for (iter = cars.begin(); iter != cars.end(); iter++)
    {
        string info = m[iter->data()];

        int time = 0;
        while (info.size() != 0)
        {
            string a, b;
            if (info.size() > 11)
            {
                a = info.substr(info.find(" ") + 1, 5);
                b = info.substr(0, info.find(" "));
                info = info.substr(12);
            }
            else
            {
                a = "23:59";
                b = info.substr(0, info.find(" "));
                info = "";
            }
            time += calc(a, b);
        }
        if (time > fees[0])
            answer.push_back(fees[1] + (int)ceil((double)(time - fees[0]) / (double)fees[2]) * fees[3]);
        else
            answer.push_back(fees[1]);
    }

    return answer;
}

int main()
{
    solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
    return 0;
}