#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct NODE
{
    int l, r;
} n[1000002];

void postOrder(int root)
{
    if (root == 0)
        return;
    postOrder(n[root].l);
    postOrder(n[root].r);
    cout << root << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int root, num, cur;
    cin >> root;
    while (cin >> num)
    {
        cur = root;
        while (true)
        {
            if (num < cur)
            {
                if (n[cur].l == 0)
                {
                    n[cur].l = num;
                    break;
                }
                else
                    cur = n[cur].l;
            }
            else
            {
                if (n[cur].r == 0)
                {
                    n[cur].r = num;
                    break;
                }
                else
                    cur = n[cur].r;
            }
        }
    }
    postOrder(root);
    return 0;
}