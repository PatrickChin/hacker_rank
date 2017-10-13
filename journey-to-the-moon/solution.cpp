// https://www.hackerrank.com/challenges/journey-to-the-moon

#include <vector>
#include <iostream>

using namespace std;

int tree_size(int pos, vector<vector<int>> const& al, vector<bool> &visited)
{
    visited[pos] = true;
    int size = 1;
    for (int next : al[pos])
        if (!visited[next])
            size += tree_size(next, al, visited);
    return size;
}

vector<int> tree_sizes(vector<vector<int>> const& al)
{
    vector<bool> visited(al.size());
    vector<int> sizes;
    for (int i = 0; i < al.size(); i++)
        if (!visited[i])
        {
            int size = tree_size(i, al, visited);
            sizes.push_back(size);
        }
    return sizes;
}

int main()
{
    int n, p;
    cin >> n >> p;

    vector<vector<int>> al(n);
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<int> const sizes = tree_sizes(al);
    long npairs = 0;
    for (int const& m : sizes)
        npairs += m * (n-m);

    cout << npairs/2 << endl;
    return 0;
}
