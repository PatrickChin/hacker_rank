// https://www.hackerrank.com/challenges/jim-and-the-orders

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<pair<int,int>> o;
    for (int i = 0; i < n; ++i)
    {
        int t, d; cin >> t >> d;
        o.push_back(make_pair(i,t+d));
    }

    sort(o.begin(), o.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    cout << o[0].first+1;
    for (int i = 1; i < n; ++i)
        cout << " " << o[i].first+1;
    return 0;
}

