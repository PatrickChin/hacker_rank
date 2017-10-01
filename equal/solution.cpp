
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
        int minchoc;
        vector<int> choc(n);
        for (int i = 0; i < n; i++)
        {
            cin >> choc[i];
            minchoc = i == 0 || choc[i] < minchoc ? choc[i] : minchoc;
        }

        for (int i = 0; i < n; i++)
            choc[i] -= minchoc;

        long minnop;
        for (int base = 0; base < 3; base++)
        {
            long nop = 0;
            for (int i = 0; i < n; i++)
            {
                int ci = choc[i] + base;
                nop += ci / 5; ci %= 5;
                nop += ci / 2; ci %= 2;
                nop += ci;
            }
            minnop = base == 0 || nop < minnop ? nop : minnop;
        }
        cout << minnop << endl;
    }
    return 0;
}
