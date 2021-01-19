#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> test;
unordered_multimap<string, string> map1;

int main(void)
{
    map1.insert({"cloth", "1"});
    map1.insert({"cloth", "2"});
    map1.insert({"cloth", "3"});
    cout << map1.find("cloth")->operator=second
         << "\n";
    return 0;
}