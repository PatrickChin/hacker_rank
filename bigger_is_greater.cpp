// https://www.hackerrank.com/challenges/bigger-is-greater

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename Iter>
bool my_next_permutation(Iter first, Iter last)
{
    if (first == last) return false;
    Iter pivot = last; --pivot;
    if (first == pivot) return false;

    Iter previous = pivot; --pivot;
    while (*pivot >= *previous)
    {
        if (pivot == first) return false;
        --pivot; --previous;
    }

    Iter successor = last; --successor;
    while (*successor <= *pivot)
    {
        --successor;
        if (successor == pivot) return false;
    }

    swap(*pivot, *successor);
    reverse(previous, last);
    return true;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        bool b = my_next_permutation(s.begin(), s.end());
        cout << (b ? s : "no answer") << endl;
    }
}

