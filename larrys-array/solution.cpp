// https://www.hackerrank.com/challenges/larrys-array

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool parity = true;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (a[i] > a[j])
                    parity = !parity;

        cout << (parity ? "YES" : "NO") << endl;
        delete[] a;
    }
    return 0;
}
