// https://www.hackerrank.com/challenges/greedy-florist

#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int const n, int const k, vector<int> c) {
    sort(c.rbegin(), c.rend());
    int cost = 0, x = 0;
    for (int i = 0; i < n; i++) {
        i % k == 0 ?  x++ : x;
        cost += x * c[i];
    }
    return cost;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}
