#include <string>
#include <map>

using namespace std;

int solution(string word)
{
    int answer = 0;
    map<char, int> m = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    int arr[5] = {781, 156, 31, 6, 1};
    for (int i = 0; i < word.size(); i++)
    {
        answer += arr[i] * m[word[i]] + 1;
    }
    return answer;
}

int main()
{
    solution("AAAAE");
    return 0;
}