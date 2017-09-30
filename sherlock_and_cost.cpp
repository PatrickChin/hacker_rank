// https://www.hackerrank.com/challenges/candies

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i]--;
        }

        long low = 0, hi = 0;
        for (int i = 1; i < n; i++)
        {
            int lo_hi = low + b[i];
            int hi_lo = hi + b[i-1];
            int lo_lo = low;
            int hi_hi = hi + abs(b[i] - b[i-1]);
            low = max(lo_lo, hi_lo);
            hi = max(lo_hi, hi_hi);
        }
        cout << max(low, hi) << endl;
    }
    return 0;
}
