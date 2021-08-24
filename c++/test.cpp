#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
class Position
{
public:
    int x;
    int y;
    int distance;
    Position(int _x, int _y, int _distance) : x(_x), y(_y), distance(_distance){};
};

int main(void)
{
    queue<Position> q;
    q.push(Position(1, 1, 1));
    q.push(Position(2, 2, 2));
    cout << q.front().distance << " " << q.front().x << " " << q.front().y << "\n";
    q.pop();
    cout << q.front().distance << " " << q.front().x << " " << q.front().y << "\n";
    return 0;
}