// https://www.hackerrank.com/challenges/kingdom-division

#include <iostream>
#include <vector>

constexpr long MOD = 1'000'000'000L + 7L;

using namespace std;

typedef vector<vector<int>> matrix;

struct tree_pair { long same, diff; };

tree_pair count_ways_impl(matrix const& al, int pos, vector<bool> &visited)
{
    visited[pos] = true;
    long same = 1, diff = 1;
    for (int next : al[pos])
        if (!visited[next])
        {
            tree_pair cur = count_ways_impl(al, next, visited);
            same = same * (cur.same + cur.diff) % MOD;
            diff = diff * cur.diff % MOD;
        }

    diff = (same - diff + MOD) % MOD;
    return { same, diff };
}

long count_ways(matrix const& al, int pos = 1)
{
    vector<bool> visited(al.size(), false);
    return 2*count_ways_impl(al, pos, visited).diff % MOD;
}

int main()
{
    int n; cin >> n;
    matrix al(n+1);
    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }

    cout << count_ways(al) << endl;

    return 0;
}
