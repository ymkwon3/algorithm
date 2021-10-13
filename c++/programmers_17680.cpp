#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int findCity(vector<string> v, string value)
{
    auto it = find(v.begin(), v.end(), value);
    if (it == v.end())
    {
        return -1;
    }
    else
        return it - v.begin();
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    int index;
    vector<string> cache;
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    for (int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        index = findCity(cache, city);
        if (index == -1)
        {
            answer += 5;
            if (cache.size() == cacheSize)
            {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
        else
        {
            answer += 1;
            cache.erase(cache.begin() + index);
            cache.push_back(city);
        }
    }
    cout << answer << "\n";
    return answer;
}

int main(void)
{
    vector<string> v = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    solution(3, v);
    return 0;
}