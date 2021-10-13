#include <bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
    Workshop(){};
    Workshop(int _s, int _d, int _e) : start_time(_s), duration(_d), end_time(_e){};
};

struct Available_Workshops
{
    int n;
    Workshop *w = new Workshop[n];
    Available_Workshops(int _n, Workshop *_w) : n(_n), w(_w){};
};

Available_Workshops *initialize(int _start_time[], int _duration[], int _n)
{
    Workshop *w = new Workshop[_n];
    for (int i = 0; i < _n; i++)
    {
        w[i] = Workshop(_start_time[i], _duration[i], _start_time[i] + _duration[i]);
    }
    Available_Workshops *aw = new Available_Workshops(_n, w);
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops *_ptr)
{
    sort(_ptr->w, _ptr->w + _ptr->n, [](Workshop A, Workshop B)
         { return A.end_time < B.end_time; });
    int cnt = 0, pre_end_time = 0;
    for (int i = 0; i < _ptr->n; i++)
    {
        if (_ptr->w[i].start_time >= pre_end_time)
        {
            cnt++;
            pre_end_time = _ptr->w[i].end_time;
        }
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
