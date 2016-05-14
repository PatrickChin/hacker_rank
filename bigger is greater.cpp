// https://www.hackerrank.com/challenges/bigger-is-greater

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// template <BidirectionalIterator It>
template <typename It>
bool my_next_permutation(It first, It last)
{

    if (first == last) return false;
    It pivot = last; --pivot;
    if (first == pivot) return false;

    It previous = pivot; --pivot;
    while (*pivot >= *previous)
    {
        if (pivot == first) return false;
        --pivot; --previous;
    }

    It successor = last; --successor;
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

