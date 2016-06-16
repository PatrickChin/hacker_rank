// https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

array<int,26> lowercase_char_freq(const string &s)
{
    array<int,26> a{};
    for (char c : s)
        a[c-'a']++;
    return a;
}

void lowercase_string_sort(string &s)
{
    auto a = lowercase_char_freq(s);
    int si = 0;
    for (char i = 0; i < 26; ++i)
        while (a[i]--)
            s[si++] = i+'a';
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
                lowercase_string_sort(sub);
                anagram_map[sub]++;
            }
        }

        int num = 0;
        for (const auto &n : anagram_map)
            num += n.second * (n.second-1) / 2;

        cout << num << endl;
    }
}
