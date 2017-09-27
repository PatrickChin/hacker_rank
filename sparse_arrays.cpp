// https://www.hackerrank.com/challenges/sparse-arrays

#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int n, q;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // check if exists?
        m[s]++;
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        cout << m[s] << "\n";
    }

    return 0;
}
