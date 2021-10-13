#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<pair<string, string>>> parsed;
    int a, b;
    string line, current, parent;
    stack<string> currentTag;
    cin >> a >> b;
    for (int i = 0; i <= a; i++)
    {
        getline(cin, line);
        if (line.size() != 0)
        {
            string s = "";
            vector<pair<string, string>> element;
            for (int j = 0; j < line.size(); j++)
            {
                if (line[j] == '<' && line[j + 1] != '/')
                { // get tag, parentTag
                    j++;
                    while (true)
                    {
                        if (line[j] == ' ' || line[j] == '>')
                        {
                            element.push_back({"tag", s});
                            if (currentTag.empty())
                                element.push_back({"parentTag", ""});
                            else
                            {
                                element.push_back({"parentTag", currentTag.top()});
                            }
                            currentTag.push(s);
                            s = "";
                            break;
                        }
                        s += line[j++];
                    }
                }
                else if (line[j] == '<' && line[j + 1] == '/')
                { // close tag
                    currentTag.pop();
                    break;
                }
                else if (line[j] == '\"')
                { // get attrValue
                    j++;
                    while (true)
                    {
                        if (line[j] == '\"')
                        {
                            element.push_back({"attrValue", s});
                            s = "";
                            break;
                        }
                        s += line[j++];
                    }
                }
                else if (line[j] == '>') // tag finished
                    break;
                else if (line[j] != ' ')
                { // get attrName and set index to attrValue start
                    while (true)
                    {
                        if (line[j] == ' ')
                        {
                            element.push_back({"attrName", s});
                            s = "";
                            break;
                        }
                        s += line[j++];
                    }
                    while (line[j + 1] != '\"')
                        j++;
                }
            }
            if (element.size() > 0)
                parsed.push_back(element);
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < parsed.size(); i++)
    {
        for (int j = 0; j < parsed[i].size(); j++)
        {
            cout << parsed[i][j].first << ":" << parsed[i][j].second << " ";
        }
        cout << "\n";
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    while (b > 0)
    {
        bool flag = true;
        current = "";
        parent = "";
        b--;
        getline(cin, line);
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '.' || line[i] == '~')
            {
                int index = 0;
                if (parent != "")
                {
                    while (true)
                    {
                        if (index >= parsed.size() || (parsed[index][0].second == current && parsed[index][1].second != parent))
                        {
                            cout << "Not Found!\n";
                            flag = false;
                            i = line.size();
                            break;
                        }
                        else if (parsed[index][0].second == current && parsed[index][1].second == parent)
                            break;
                        index++;
                    }
                }
                if (line[i] == '~' && parent == "")
                {
                    while (true)
                    {
                        if (index >= parsed.size() || (parsed[index][0].second == current && parsed[index][1].second != ""))
                        {
                            cout << "Not Found!\n";
                            flag = false;
                            i = line.size();
                            break;
                        }
                        else if (parsed[index][0].second == current && parsed[index][1].second == "")
                            break;

                        index++;
                    }
                }
                parent = current;
                current = "";
            }
            else
            {
                current += line[i];
            }
        }
        int index = 0;
        while (flag)
        {
            if (parsed[index][0].second == parent)
            {
                if (parsed[index].size() == 2)
                {
                    cout << "Not Found!\n";
                    flag = false;
                }
                else
                {
                    for (int i = 2; i < parsed[index].size(); i++)
                    {
                        if (parsed[index][i].first == "attrName" && parsed[index][i].second == current)
                        {
                            cout << parsed[index][i + 1].second << "\n";
                            flag = false;
                            break;
                        }
                        if (i == parsed[index].size() - 1)
                        {
                            cout << "Not Found!\n";
                            flag = false;
                        }
                    }
                }
            }
            index++;
        }
    }

    return 0;
}
