#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void dfs_visit(int pos, vector<vector<int>> const& al, vector<bool> &visited)
{
    visited[pos] = true;
    for (int const& next : al[pos])
        if (!visited[next])
            dfs_visit(next, al, visited);
}

int count_groups(vector<vector<int>> const& al)
{
    int count = 0;
    vector<bool> visited(al.size(), false);
    for (int i = 0; i < al.size(); i++)
    {
        if (visited[i])
            continue;
        count++;
        dfs_visit(i, al, visited);
    }
    return count;
}

int main()
{
    cout << "Hello\n";

    int q = 0;
    cin >> q;

    while(q--)
    {
        long n, m, clib, croad;
        cin >> n >> m >> clib >> croad;

        vector<vector<int>> al(n, vector<int>());
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        if (croad >= clib)
        {
            long cost = clib * n;
            cout << cost << endl;
            continue;
        }

        long nlibs = count_groups(al);
        long nroads = (long) n - nlibs;
        long cost = (nlibs * clib) + (nroads * croad);
        cout << cost << " " << n << " " << nlibs << endl;
    }
    return 0;
}
