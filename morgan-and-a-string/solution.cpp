// https://www.hackerrank.com/challenges/morgan-and-a-string

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef string::iterator StringIter;

bool incfwd(StringIter i, StringIter j)
{
    assert(*i == *j);
    while (true)
    {
        ++i, ++j;
        if (*i == *j)
            continue;
        return *i < *j;
    }
}

bool incfwd(StringIter ai, StringIter bi, StringIter aj, StringIter bj)
{
    assert(*i == *j);
    while (true)
    {
        ai++, bi++, aj++, bj++;
        if (*ai == *bi)
        {
            if (*ai == *aj)
                continue;
            else
                return *ai < *aj;
        }
        else
            return incfwd(*ai < *bi ? ai : bi, aj, bj);
    }
}

int main(int argc, char *argv[])
{
    int t; cin >> t;
    while (t--)
    {
        string a, b, s;
        cin >> a >> b;
        a.push_back('z');
        b.push_back('z');
        s.resize(a.length() + b.length());

        StringIter ai = a.begin();
        StringIter bi = b.begin();
        bool jset = false;
        StringIter aj, bj;
        StringIter si = s.begin();
        while (ai != a.end() && bi != b.end())
        {
            if (jset)
            {
                if (*ai == *bi)
                {
                    if (*ai < *aj)
                    {
                        *si++ = *ai;
                        ai++, bi++;
                    }
                    else if (*ai > *aj)
                    {
                        *si++ = *aj;
                        aj++, bj++;
                    }
                    else // if (*ai == *aj)
                    {
                        *si++ = *ai;
                        incfwd(ai, bi, aj, bj) ? ai++, bi++ : aj++, bj++;
                    }
                }
                else if (*ai < *bi)
                {
                    if (*ai < *aj)
                    {
                        *si++ = *ai++;
                    }
                    else if (*ai > *aj)
                    {
                        *si++ = *aj;
                        aj++, bj++;
                    }
                    else // if (*ai == *aj)
                    {
                        *si++ = *ai;
                        incfwd(ai, aj, bj) ? ai++ : aj++, bj++;
                    }
                }
                else if (*ai > *bi)
                {
                    if (*bi < *bj)
                    {
                        *si++ = *bi++;
                    }
                    else if (*bi > *bj)
                    {
                        *si++ = *bj;
                        aj++, bj++;
                    }
                    else // if (*bi == *bj)
                    {
                        *si++ = *bi;
                        incfwd(bi, aj, bj) ? bi++ : aj++, bj++;
                    }
                }

                if (aj == ai || bj == bi)
                    jset = false;
            }
            else
            {
                if (*ai == *bi)
                {
                    jset = true;
                    aj = ai;
                    bj = bi;
                    *si++ = *ai;
                    ai++, bi++;
                }
                else
                {
                    *si++ = *ai < *bi ? *ai++ : *bi++;
                }
            }
        }

        copy(ai, a.end(), si);
        copy(bi, b.end(), si);

        s.pop_back();
        s.pop_back();
        cout << s << "\n";
    }

    return 0;
}
