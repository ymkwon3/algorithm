#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int index;
    int value;
    int total;
    vector<Node *> children;

    Node(int _index, int _value) : index(_index), value(_value), total(_value) {}
};

int calculateTotal(Node *root)
{
    if (root->children.empty())
        return root->value;
    for (Node *node : root->children)
    {
        root->total += calculateTotal(node);
    }
    return root->total;
}

void mostBalanced(Node *root, const int total, int &diff)
{
    if (root == NULL)
        return;
    int d = abs(total - 2 * root->total);
    if (d < diff)
        diff = d;
    for (Node *child : root->children)
        mostBalanced(child, total, diff);
}

int partitioning(vector<int> parent, vector<int> files_size)
{
    vector<Node *> nodes(parent.size());
    Node *root = NULL;
    for (int i = 0; i < parent.size(); i++)
    {
        Node *node = new Node(i, files_size[i]);
        nodes[i] = node;
        if (parent[i] != -1)
        {
            nodes[parent[i]]->children.push_back(node);
        }
        else
        {
            root = node;
        }
    }
    int total = calculateTotal(root);
    int diff = total;

    mostBalanced(root, total, diff);
    return diff;
}

int main()
{
    int parent_count, files_count;
    cin >> parent_count;
    vector<int> parent(parent_count);
    for (int i = 0; i < parent_count; i++)
    {
        cin >> parent[i];
    }
    cin >> files_count;
    vector<int> files_size(files_count);
    for (int i = 0; i < files_count; i++)
    {
        cin >> files_size[i];
    }

    int result = partitioning(parent, files_size);

    return 0;
}