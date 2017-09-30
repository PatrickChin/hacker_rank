// https://www.hackerrank.com/challenges/compare-the-triplets

#include <iostream>

using namespace std;

int main()
{
    int a[3], b[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> b[i];
    int ascore = 0, bscore = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == b[i])
            continue;
        a[i] > b[i] ? ascore++ : bscore++;
    }
    cout << ascore << " " << bscore << "\n";
    return 0;
}
