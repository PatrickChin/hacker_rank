// https://www.hackerrank.com/challenges/bear-and-steady-gene

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

inline bool all_gt_eq(const array<int,4> &a, const array<int,4> &b)
    { return a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2] && a[3]>=b[3]; }

int main(int argc, char *argv[])
{
    int n; cin >> n;
    int m = n/4;

    string s; cin >> s;
    for (char &c : s) 
        switch (c)
        {
            case 'A': c = 0; break;
            case 'C': c = 1; break;
            case 'T': c = 2; break;
            case 'G': c = 3; break;
        }

    array<int,4> req_freq;
    req_freq.fill(-m);
    for (const char &c : s)
        req_freq[c]++;

    array<int,4> curr_freq{};
    int end = 0;
    while (end < n)
    {
        curr_freq[s[end]]++;
        if (all_gt_eq(curr_freq, req_freq))
            break;
        end++;
    }

    int start = 0, mindiff = end;
    while (end < n)
    {
        while (true)
        {
            if (curr_freq[s[start]]-1 < req_freq[s[start]])
            {
                mindiff = min(mindiff, end-start);
                break;
            }
            curr_freq[s[start]]--;
            start++;
        }
        end++;
        curr_freq[s[end]]++;
    }

    // +1 is added since start and end are inclusive
    cout << mindiff+1 << endl;
    return 0;
}
