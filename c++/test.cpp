#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>

using namespace std;
map<int, vector<int>> m;
vector<int> v;
vector<int>::iterator iter = v.begin();
priority_queue<pair<int, int>> pq;
int main(void)
{
    pq.push(make_pair(0, 1));
    pq.push(make_pair(1, 1));
    pq.push(make_pair(2, 1));
    pq.push(make_pair(3, 1));
    int cost = -pq.top().first;
    cout << cost << "\n";
    return 0;
}