// https://www.hackerrank.com/challenges/flipping-the-matrix

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
        int n2 = 2*n;

        int mat[256][256];
        for (int i = 0; i < n2; ++i)
            for (int j = 0; j < n2; ++j)
                cin >> mat[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = max(mat[i][j], mat[n2-1-i][j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = max(mat[i][j], mat[i][n2-1-j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = max(mat[i][j], mat[n2-1-i][n2-1-j]);

        long matsum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matsum += mat[i][j];

        cout << matsum << endl;
    }
    return 0;
}
