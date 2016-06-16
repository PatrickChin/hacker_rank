// https://www.hackerrank.com/challenges/sherlock-and-valid-string

#include <string>
#include <array>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string s; cin >> s;
    array<int, 26> freq{};
    for (char &c : s)
        freq[c-'a']++;

    int f1, f2, nf1=0, nf2=0;
    for (int &i : freq)
    {
        if (i == 0)  continue;

        if (f1 == i || nf1 == 0)
        {
            f1 = i;
            nf1++;
            continue;
        }

        if (f2 == i || nf2 == 0)
        {
            f2 = i;
            nf2++;
            continue;
        }

        nf2 = 2;
        nf1 = 2;
        break;
    }

    cout << ((nf1 < 2 || nf2 < 2) ? "YES" : "NO") << endl;

    return 0;
}
