#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> input;
int n, m;

void init()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        input[a]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cout << input[a] << " ";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    return 0;
}