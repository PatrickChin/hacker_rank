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

    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i])
            k--;

    if (k < 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n/2; i++)
    {
        int j = n-1-i;
        if (s[i] == '9' && s[j] == '9')
        {
            continue;
        }
        else if (s[i] == '9' || s[j] == '9')
        {
            s[i] = '9';
            s[j] = '9';
        }
        else if (s[i] == s[j] && k > 1)
        {
            k -= 2;
            s[i] = '9';
            s[j] = '9';
        }
        else if (s[i] != s[j] && k > 0)
        {
            k--;
            s[i] = '9';
            s[j] = '9';
        }
        else if (s[i] != s[j])
        {
            s[i] = max(s[i], s[j]);
            s[j] = s[i];
        }
    }

    if (n % 2 == 1 && k > 0)
    {
        s[n/2] = '9';
    }

    cout << s;
    return 0;
}
