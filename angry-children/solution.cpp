// https://www.hackerrank.com/challenges/angry-children

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int hi = k-1, lo = 0;
    long minfair = a[n-1];
    while (hi < n)
    {
        long curfair = a[hi++] - a[lo++];
        minfair = curfair < minfair ? curfair : minfair;
    }

    cout << minfair << endl;
    return 0;
}

