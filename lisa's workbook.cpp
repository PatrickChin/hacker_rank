// https://www.hackerrank.com/challenges/bear-and-workbook

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    int page = -1, num = 0;
    for (int chapter = 0; chapter < n; chapter++)
        for (int problem = 0; problem < t[chapter]; problem++)
        {
            if (problem % k == 0 || problem-1 == t[chapter]) page++;
            if (problem == page) num++;
        }

    cout << num << endl;

    return 0;
}

