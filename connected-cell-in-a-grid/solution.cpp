// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int countfillgroup(vector<vector<int>> &mat, int i, int j, int num)
{
    int count = 1;
    mat[i][j] = num;
    for (int di = i-1; di <= i+1; di++)
        for (int dj = j-1; dj <= j+1; dj++)
        {
            if (di == i && dj == j)
                continue;
            if (di < 0 || dj < 0)
                continue;
            if (di >= mat.size() || dj >= mat[0].size())
                continue;
            if (mat[di][dj] == 1)
                count += countfillgroup(mat, di, dj, num);
        }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int groupnum = 2, maxsize = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 1)
            {
                int cursize = countfillgroup(mat, i, j, groupnum++);
                maxsize = cursize > maxsize ? cursize : maxsize;
            }

    cout << maxsize << endl;
    return 0;
}
