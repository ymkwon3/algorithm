#include <iostream>
#include <string>

using namespace std;

string input;

void init()
{
    int cnt = 1;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            cnt++;
    }
    if (input[0] == ' ')
        cnt--;
    if (input[input.length() - 1] == ' ')
        cnt--;
    cout << cnt << "\n";
}
int main(void)
{
    init();

    return 0;
}