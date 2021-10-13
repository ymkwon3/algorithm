#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades)
{
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] % 5 >= 3 && grades[i] + 5 - grades[i] % 5 >= 40)
            grades[i] += 5 - grades[i] % 5;
    }
    return grades;
}

int main()
{
    gradingStudents({4, 73, 67, 38, 33});
    return 0;
}