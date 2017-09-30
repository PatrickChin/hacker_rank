// https://www.hackerrank.com/challenges/sparse-arrays

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;

    // keys are sorted!
    map<int, int> v;
    for (int i = 0; i < m; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        v[a]   += k;
        v[b+1] -= k;
    }

    long maxval = 0, val = 0;
    for (auto it = v.begin(), end = v.end(); it != end; ++it) {
        val += it->second;
        maxval = max(val, maxval);
    }

    cout << maxval << "\n";
    return 0;
}
