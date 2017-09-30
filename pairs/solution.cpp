// https://www.hackerrank.com/challenges/pairs

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int size = a.size();
    int count = 0;
    int low = 0, hi = 1;
    while (hi < size)
    {
        int dif = a[hi] - a[low];
        if (dif == k)
            hi++, low++, count++;
        else if (dif < k)
            hi++;
        else if (dif > k)
            low++;
    }

    cout << count << endl;
    return 0;
}
