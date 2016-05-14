// https://www.hackerrank.com/challenges/encryption

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length();
    float sqlen = sqrt(len);
    int rows = floor(sqlen);
    int cols = ceil(sqlen);

    if (rows*cols < len)
        cols > rows ?  rows++ : cols++;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            int k = j*cols + i;
            if (k < len)
                cout << s[k];
        }
        cout << " ";
    }
}

