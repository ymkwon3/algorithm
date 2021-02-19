#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> m;
int n;

void preorder(char value)
{
    cout << value;
    if (m[value].first != '.')
        preorder(m[value].first);
    if (m[value].second != '.')
        preorder(m[value].second);
    if (value == 'A')
        cout << "\n";
}

void inorder(char value)
{
    if (m[value].first != '.')
        inorder(m[value].first);
    cout << value;
    if (m[value].second != '.')
        inorder(m[value].second);
    if (value == 'A')
        cout << "\n";
}

void postorder(char value)
{
    if (m[value].first != '.')
        postorder(m[value].first);
    if (m[value].second != '.')
        postorder(m[value].second);
    cout << value;
    if (value == 'A')
        cout << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        m[a] = make_pair(b, c);
    }

    preorder('A');
    inorder('A');
    postorder('A');

    return 0;
}