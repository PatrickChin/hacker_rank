// https://community.topcoder.com/stat?c=problem_statement&pm=13642

#include <string>
#ifdef CHECK
#include <cstdio>
#endif
#include <cmath>

using namespace std;

class AB
{
public:
    bool checkString(const string s, const int n, const int k)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'A')
                continue;
            for (int j = i+1; j < n; ++j)
                if (s[j] == 'B')
                    sum++;
        }
        return sum == k;
    }

    string createString(const int n, const int k)
    {
        int sq = n*n - 4*k;
        if (sq < 0)
            return string();
        sq = sqrt(sq);

        int a = (n - sq) / 2;
        int d = k - a*(n-a);

        if (a < 0 || d < 0)
            return string();

        string s = string(a, 'A') + string(n-a, 'B');

        if (d > 0)
            s[n-a-d-1] = 'A';

#ifdef CHECK
        bool b = checkString(s, n, k);
        if (!b) printf("n=%d k=%d: nope s=%s\n", n, k, s.c_str());
#endif

        return s;
    }
};

#ifdef CHECK
int main()
{
    AB ab;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < i*(i+1)/2; ++j) {
            ab.createString(i, j);
        }
    }
    return 0;
}
#endif
