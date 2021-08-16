#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;
    virtual void getdata() = 0;

    virtual void putdata() = 0;
};

class Professor : public Person
{
public:
    Professor()
    {
        cur_id = ++id;
    }
    void getdata()
    {
        cin >> name >> age >> publications;
    }

    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << cur_id << "\n";
    }

private:
    int publications;
    int cur_id;
    static int id;
};

class Student : public Person
{
public:
    Student()
    {
        cur_id = ++id;
    }
    void getdata()
    {
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    }
    void putdata()
    {
        int sum = marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5];
        cout << name << " " << age << " " << sum << " " << cur_id << "\n";
    }

private:
    vector<int> marks = {0, 0, 0, 0, 0, 0};
    int cur_id;
    static int id;
};

int Professor::id = 0;
int Student::id = 0;

int main()
{

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
