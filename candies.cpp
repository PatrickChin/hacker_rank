// https://www.hackerrank.com/challenges/candies/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        cin >> ratings[i];


    vector<long> candies(n, 1);

    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;

    for (int i = n-2; i >= 0; i--)
        if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;


    {
        bool correct = true;
        int i = 1;
        for (; i < n-1 && correct; i++)
        {
            correct = correct && ratings[i] > ratings[i-1] || candies[i] < candies[i-1];
            correct = correct && ratings[i] > ratings[i+1] || candies[i] < candies[i+1];
        }
        cout << (correct ? "correct" : "wrong") << " " << i << "\n";

        if (!correct)
        {
            for (int j = max(0, i-20); j < min(n, i+20); j++)
                cout << ratings[j] << " ";
            cout << "\n";

            for (int j = max(0, i-20); j < min(n, i+20); j++)
                cout << candies[j] << " ";
            cout << "\n";
        }
    }

    cout << accumulate(candies.begin(), candies.end(), 0L) << endl;
    return 0;
}
