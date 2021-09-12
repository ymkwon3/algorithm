#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2)
{
    string answer = "NO";
    int location1 = x1, location2 = x2;
    while (location1 < location2)
    {
        location1 += v1, location2 += v2;
        if (location1 == location2)
            answer = "YES";
    }
    cout << answer << "\n";
    return answer;
}

int main()
{
    kangaroo(0, 2, 5, 3);
    return 0;
}