#include <iostream>
#include <vector>

using namespace std;

vector<int> test(1, 0);

int main(void)
{
    test[0]++;
    cout << test[0] << "\n";
    return 0;
}