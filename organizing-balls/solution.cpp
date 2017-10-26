// https://www.hackerrank.com/challenges/organizing-containers-of-balls

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;

        vector<vector<int>> m(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];

        vector<long> rowsum(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                rowsum[i] += m[i][j];

        vector<long> colsum(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                colsum[j] += m[i][j];

        sort(begin(colsum), end(colsum));
        sort(begin(rowsum), end(rowsum));

        bool possible = true;
        for (int i = 0; possible && i < n; i++)
            possible = possible && rowsum[i] == colsum[i];

        cout << (possible ? "Possible\n" : "Impossible\n");
    }

    return 0;
}
