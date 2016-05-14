// https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <unordered_map>

using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1,T2> p)
    { return out << "(" << p.first << "," << p.second << ")"; }

template<typename Container>
ostream& ostream_container(ostream& out, const Container arr)
{
    auto first = arr.begin();
    auto last = arr.end();
    if (first == last)
        return out << "[]";
    out << '[' << *first++;
    for (; first != last; first++)
        out << ", " << *first;
    return out << ']';
}

template<typename T, unsigned int L>
ostream& operator<<(ostream& out, const array<T,L> arr)
    { return ostream_container(out, arr); }

template<typename Key, typename T>
ostream& operator<<(ostream& out, const unordered_map<Key,T> map)
    { return ostream_container(out, map); }

template<int lo, int hi>
array<int,hi-lo+1> str_freq(string &s)
{
    array<int,hi-lo+1> a;
    a.fill(0);
    for (char c : s)
        a[c-lo]++;
    return a;
}

string& lowercase_string_sort(string &s)
{
    auto a = str_freq<'a','z'>(s);
    int si = 0;
    for (char i = 'a'; i <='z'; ++i) while (a[i-'a']--)
        s[si++] = i;
    return s;
}

int main(void)
{
    int t; cin >> t;
    while (t--)
    {
        unordered_map<string, int> anagram_map;
        string s; cin >> s;
        int slen = s.length();
        for (int len = 1; len < slen; ++len)
        {
            for (int pos = 0; pos <= slen-len; ++pos)
            {
                string sub = s.substr(pos,len);
                sub = lowercase_string_sort(sub);
                anagram_map[sub]++;
            }
        }
        int num = 0;
        // cout << anagram_map << endl;
        for (auto n : anagram_map)
            num += n.second * (n.second-1) / 2;

        cout << num << endl;
    }
}
