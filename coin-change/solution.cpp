// https://www.hackerrank.com/challenges/coin-change/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> c{};
    c.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int ci; cin >> ci;
        if (ci <= n)
            c.push_back(ci);
    }
    sort(c.begin(), c.end());

    vector<int> ways(n+1, 0);
    for (int i = 1, j = 0; i < n+1; i++)
    {
        if (j < m && c[j] == i)
        {
            j++;
            ways[i] = 1;
        }
        for (int k = 1; k < i/2+1; k++)
        {
            ways[i] += ways[k] * ways[i-k];
        }
    }

    cout << ways[n] << endl;

    return 0;
}
