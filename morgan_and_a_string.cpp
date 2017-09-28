// https://www.hackerrank.com/challenges/morgan-and-a-string/problem

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int t; cin >> t;
    while (t--)
    {
        string a, b, s;
        cin >> a >> b;
        s.resize(a.length() + b.length());

        string::iterator ai = a.begin();
        string::iterator bi = b.begin();
        string::iterator si = s.begin();
        string::iterator aend = a.end();
        string::iterator bend = b.end();
        while (ai != aend && bi != bend)
            *si++ = lexicographical_compare(ai, aend, bi, bend) ?  *ai++ : *bi++;
        copy(ai, aend, si);
        copy(bi, bend, si);

        cout << s << "\n";
    }

    return 0;
}
