#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b;
    vector<string> arr;
    string tmp;
    // cin >> a >> b;
    a = 10, b = 10;
    // for (int i = 0; i < a; i++)
    // {
    //     getline(cin, tmp);
    //     arr.push_back(tmp);
    //     cout << tmp << "\n";
    // }
    arr.push_back("<a value = \"GoodVal\">");
    arr.push_back("<b value = \"BadVal\" size = \"10\">");
    arr.push_back("</b>");
    arr.push_back("<c height = \"auto\">");
    arr.push_back("<d size = \"3\">");
    arr.push_back("<e strength = \"2\">");
    arr.push_back("</e>");
    arr.push_back("</d>");
    arr.push_back("</c>");
    arr.push_back("</a>");

    while (b > 0)
    {
        b--;
        getline(cin, tmp);
        int idx = 0;
        int arrIdx = 0;
        string name = "";
        char cur;
        while (idx < tmp.size())
        {
            if (tmp.size() == idx)
                break;
            cur = tmp[idx];
            cout << "cur : " << cur << "\n";

            if (cur == '.')
            {
                if (arr[arrIdx][1] == '/')
                {
                    cout << "Not Found!\n";
                    break;
                }
                if (arr[arrIdx].find('<' + name) != string::npos)
                {
                    arrIdx++;
                    name = "";
                }
                else
                {
                    arrIdx++;
                    continue;
                }
            }
            else if (cur == '~')
            {
                if (arr[arrIdx].find('<' + name) == string::npos)
                {
                    arrIdx++;
                    continue;
                }
                name = "";
            }
            else
            {
                name += cur;
            }
            idx++;
        }

        if (arr[arrIdx].find(name) != string::npos)
        {
            int attrIdx = arr[arrIdx].find(name) + name.size();
            string value = "";
            bool stop = true;
            while (stop)
            {
                if (arr[arrIdx][attrIdx++] == '\"')
                {
                    cur = arr[arrIdx][attrIdx];
                    while (cur != '\"')
                    {
                        value += cur;
                        cur = arr[arrIdx][++attrIdx];
                    }
                    stop = false;
                }
            }
            cout << value << "\n";
        }
        else
        {
            cout << "Not Found!\n";
        }
    }
    return 0;
}
