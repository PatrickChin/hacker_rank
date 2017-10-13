// https://www.hackerrank.com/challenges/journey-to-the-moon

#include <vector>
#include <iostream>

using namespace std;

long tree_size(int pos, vector<vector<long>> const& al, vector<bool> &visited)
{
    visited[pos] = true;
    long size = 1;
    for (long next : al[pos])
        if (!visited[next])
            size += tree_size(next, al, visited);
    return size;
}

vector<long> tree_sizes(vector<vector<long>> const& al)
{
    vector<bool> visited(al.size());
    vector<long> sizes;
    for (int i = 0; i < al.size(); i++)
        if (!visited[i])
        {
            long size = tree_size(i, al, visited);
            sizes.push_back(size);
        }
    return sizes;
}

int main()
{
    long n, p;
    cin >> n >> p;

    vector<vector<long>> al(n);
    for (int i = 0; i < p; i++)
    {
        long a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<long> const sizes = tree_sizes(al);
    long npairs = n*(n-1)/2;
    for (int i = 0; i < sizes.size(); i++)
    {
        long m = sizes[i];
        npairs -= m*(m-1)/2;
    }

    cout << npairs << endl;
    return 0;
}
