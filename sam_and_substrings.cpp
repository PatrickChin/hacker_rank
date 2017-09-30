// https://www.hackerrank.com/challenges/sam-and-substrings

#include <iostream>

using namespace std;

int main()
{
    const long tmod = 1e9 + 7;
    string s; cin >> s;
    for (int i = s.length()-1; i >= 0; i--)
        s[i] -= '0';
    
    long mul = 1, len = s.length();
    long t = 0;
    for (int i = s.length()-1; i >= 0; i--)
    {
        t = (t + s[i] * mul * len) % tmod;
        mul = (mul*10 + 1) % tmod;
        len--;
    }
    cout << t << endl;
    return 0;
}
