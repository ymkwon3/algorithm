#include <bits/stdc++.h>
using namespace std;

class Box
{
private:
    int l, b, h;

public:
    Box()
    {
        l = b = h = 0;
    }
    Box(int len, int br, int hg)
    {
        l = len, b = br, h = hg;
    }
    Box(const Box &B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    long long CalculateVolume()
    {
        return (long long)l * b * h;
    }
    friend bool operator<(const Box &a, const Box &b)
    {
        if ((a.l < b.l) || ((a.b < b.b) && (a.l == b.l)) || (a.h < b.h) && (a.l == b.l))
            return true;
        else
            return false;
    }

    friend ostream &operator<<(ostream &out, Box &B)
    {
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
        return out;
    }
};

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}