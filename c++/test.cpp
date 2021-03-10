#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>

using namespace std;
map<int, vector<int>> m;
vector<int> v;
vector<int>::iterator iter = v.begin();
priority_queue<pair<int, int>> pq;
int main(void)
{
    string a = "test";
    string b = "tssw";
    int g = a.find(b[3]);
    cout << g << "\n";
    return 0;
}