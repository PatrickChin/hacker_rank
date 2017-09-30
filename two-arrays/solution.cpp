// https://www.hackerrank.com/challenges/two-arrays

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end(), less<int>());
        sort(b.begin(), b.end(), greater<int>());

        bool yes = true;
        for (int i = 0; yes && i < n; ++i)
            yes = (a[i]+b[i]) >= k;

        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}


