#include <iostream>
#include <string>

using namespace std;
string input;

void init()
{
    cin >> input;
}

void palindrome()
{
    while (true)
    {
        init();
        if (input[0] == '0')
            break;
        if (input.size() == 1)
        {
            cout << "yes"
                 << "\n";
        }
        

        for (int i = 0; i < input.size() / 2; i++)
        {
            if (input[i] != input[input.size() - 1 - i])
            {
                cout << "no"
                     << "\n";
                break;
            }
            if (i == (input.size() / 2) - 1)
            {
                cout << "yes"
                     << "\n";
            }
        }
    }
}

int main(void)
{
    palindrome();
    return 0;
}