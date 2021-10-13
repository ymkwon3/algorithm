#include <iostream>
using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    int a, b;
    for (int i = 0; i < testcase; i++)
    {
        cin >> a >> b;
        int answer = 1;
        for (int j = 0; j < b; j++)
        {
            answer = (answer * a) % 10;
        }
        if (answer == 0)
            answer = 10;
        cout << answer << "\n";
    }
    return 0;
}