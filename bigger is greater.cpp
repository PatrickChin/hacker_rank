// https://www.hackerrank.com/challenges/bigger-is-greater

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// template <BidirectionalBidirIterator BidirIt>
template <class BidirIt>
bool my_next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt pivot = last; --pivot;
    if (first == pivot) return false;

    BidirIt previous = pivot; --pivot;
    while (*pivot >= *previous)
    {
        if (pivot == first) return false;
        --pivot; --previous;
    }

    BidirIt successor = last; --successor;
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

