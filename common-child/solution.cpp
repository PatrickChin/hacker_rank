// https://www.hackerrank.com/challenges/common-child

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string a, b;
    cin >> a >> b;

    const int len = a.length();
    vector<vector<int>> mat(len+1, vector<int>(len+1));

    for (int i = 0; i < len+1; i++)
    {
        mat[i][0] = 0;
        mat[0][i] = 0;
    }

    int maxlen = 0;
    for (int i = 1; i < len+1; i++)
    {
        for (int j = 1; j < len+1; j++)
        {
            int tmp = max(mat[i-1][j], mat[i][j-1]);
            mat[i][j] = max(tmp, mat[i-1][j-1]);
            if (a[i-1] == b[j-1])
            {
                mat[i][j] = mat[i-1][j-1]+1;
                maxlen = mat[i][j] > maxlen ? mat[i][j] : maxlen;
            }
        }
    }

    cout << maxlen << endl;
    return 0;
}
