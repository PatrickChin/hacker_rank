// https://www.hackerrank.com/challenges/two-strings

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string a, b; 
        cin >> a >> b;

        if (a.length() > b.length()) 
            swap(a, b);

        array<int, 26> ca; 
        ca.fill(0);

        for (char c : a)
            ca[c-'a']++;

        bool has_sub = false;
        for (char c : b)
            if (ca[c-'a'])
            {
                has_sub = true;
                break;
            }

        cout << (has_sub ? "YES" : "NO") << endl;
    }

    return 0;
}

