// https://www.hackerrank.com/challenges/an-interesting-game-1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename Iter>
int count_turns(Iter first, Iter const& last)
{
    int turns = 0;
    int curmax = 0;
    while (first != last)
    {
        if (*first > curmax)
        {
            curmax = *first;
            turns++;
        }
        first++;
    }
    return turns;
}

int main()
{
    int g;
    cin >> g;
    while (g--)
    {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        int turns = count_turns(A.begin(), A.end());
        cout << (turns % 2 == 0 ?  "ANDY\n" : "BOB\n");
    }
    return 0;
}
