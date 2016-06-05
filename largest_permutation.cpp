// https://www.hackerrank.com/challenges/largest-permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    long n, k; cin >> n >> k;
    vector<long> v(n), w(n);

    for (int i=0; i<n; ++i)
    {
        cin >> v[i]; 
        w[n-v[i]] = i;
    }

    for (int i=0; k && i<n; ++i)
        if (w[i] != i)
        {
            long vi = v[i], wi = w[i];
            swap(v[i],v[wi]);
            swap(w[i],w[n-vi]);
            --k;
        }

    for (int i=0; i<n; ++i)
        cout << v[i] << " ";

    return 0;
}
