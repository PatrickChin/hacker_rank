// https://www.hackerrank.com/challenges/richie-rich

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> changed(n, 0);
    for (int i = 0; i < n/2; i++)
    {
        int j = n-1-i;
        if (s[i] != s[j])
        {
            k--;
            int ij = s[i] > s[j] ? i : j;
            changed[ij] = 1;
            s[i] = s[ij];
            s[j] = s[ij];
        }
    }

    if (k < 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n/2 && k > 0; i++)
    {
        int j = n-1-i;
        if (s[i] == '9')
            continue;
        if (k > 1 && changed[i] == 0 && changed[j] == 0)
        {
            k -= 2;
            s[i] = s[j] = '9';
        }
        else if (k > 0 && (changed[i] || changed[j]))
        {
            k -= 1;
            s[i] = s[j] = '9';
        }
    }

    if (n % 2 == 1 && k > 0)
    {
        s[n/2] = '9';
    }

    cout << s;
    return 0;
}
