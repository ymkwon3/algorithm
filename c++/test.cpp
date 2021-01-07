#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> test;

int main(void)
{
    test.push(1);
    test.push(5);
    test.push(3);

    cout << test.top();
    return 0;
}