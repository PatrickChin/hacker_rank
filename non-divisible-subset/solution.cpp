// https://www.hackerrank.com/challenges/non-divisible-subset

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n; cin >> n;
    int k; cin >> k;
    vector<int> c(k);
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        c[val % k]++;
    }

    int size = 0;
    for (int i = 1; i < (k+1)/2; ++i) { // +1 to inc lower half of odd
        int a = c[i];
        int b = c[k-i];
        size += a > b ? a : b;
    }

    if (c[0] > 0) size++;
    if (k%2 == 0 && c[k/2] > 0) size++;

    cout << size << "\n";
    return 0;
}
