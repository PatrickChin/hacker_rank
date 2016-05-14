// https://www.hackerrank.com/challenges/mark-and-toys

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k; cin >> n >> k;
    vector<int> p(n);

    for (int i = 0; i < n; ++i)
        cin >> p[i];

    sort(p.begin(), p.end());

    int ans = 0, cost = 0;
    for (int i = 0; i < n; ++i)
    {
        cost += p[i];
        if (cost <= k) ans++;
        else break;
    }
    cout << ans;

    return 0;
}

